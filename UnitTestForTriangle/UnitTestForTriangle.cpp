#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForTriangle
{
	TEST_CLASS(UnitTestForTriangle)
	{
	public:
		// Test case for scalene triangle
		TEST_METHOD(TestForScaleneTriangle)
		{
			int side1 = 5;
			int side2 = 7;
			int side3 = 10;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", result);
		}

		// Test case for isosceles triangle
		TEST_METHOD(TestForIsoscelesTriangle)
		{
			int side1 = 8;
			int side2 = 10;
			int side3 = 8;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);
		}

		// Test case for equilateral triangle
		TEST_METHOD(TestForEquilateralTriangle)
		{
			int side1 = 9;
			int side2 = 9;
			int side3 = 9;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", result);	// expected			// actual
		}

		//	Test case for not a triangle(using zero)
		TEST_METHOD(TestForNotATriangle1) {
			int side1 = 0;
			int side2 = 8;
			int side3 = 8;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);		//expected		//actual
		}

		//	Test case for not a triangle(using -negative)
		TEST_METHOD(TestForNotATriangle2) {
			int side1 = -8;
			int side2 = 8;
			int side3 = 8;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);		//expected			//actual
		}

		//	Test case for not a triangle(Triangle inequality viloation)
		TEST_METHOD(TestForNotATriangle3) {
			int side1 = 3;
			int side2 = 4;													// side1 + side2 > side 3  -- false 
			int side3 = 8;													// side2 + side3 > side 1  -- True 
			char* result = analyzeTriangle(side1, side2, side3);			// side1 + side3 > side 2  -- True
			Assert::AreEqual("Not a triangle", result);					//	since condition 1 fails these sides cannot form the triangle
		}
		// Test case for the angle of triangle  (checking for valid triangle for scalene) 
		TEST_METHOD(TestForTriangleAngles) {
			double angleA, angleB, angleC;
			int side1 = 8;
			int side2 = 15;
			int side3 = 17;
			bool isValid = TriangleAngles(side1, side2, side3, &angleA, &angleB, &angleC);
			Assert::IsTrue(isValid);
			Assert::AreEqual(28.072, angleA, 0.01);			// expected after using coine law we get == 28.72	//actual from the function we have implemented in the function ---	// 0.01 fot tolerance case that shows it is close the expected result
			Assert::AreEqual(61.928, angleB, 0.01);
			Assert::AreEqual(90, angleC, 0.01);

		}
		// test case for invalid traingle  i.e., those sides which doesnt form a triangle 
		TEST_METHOD(TestInvlaidTriangleAngles) {
			double angleA, angleB, angleC;
			int side1 = 1;
			int side2 = 2;
			int side3 = 3;
			bool isValid = TriangleAngles(side1, side2, side3, &angleA, &angleB, &angleC);
			Assert::IsFalse(isValid);			// test case to check the function is invalid, It should return false for those cases.
		}
		// Test case for equilateral triangle angle and checking the vaild side too.
		TEST_METHOD(TestForEquilateralTriangleAngles) {
			double angleA, angleB, angleC;
			int side1 = 12;
			int side2 = 12;
			int side3 = 12;
			bool isValid = TriangleAngles(side1, side2, side3, &angleA, &angleB, &angleC);
			Assert::IsTrue(isValid);
			Assert::AreEqual(60, angleA, 0.01);			// expected after using coine law we get == 60	//actual from the function we have implemented in the function ---	// 0.01 fot tolerance case that shows it is close the expected result
			Assert::AreEqual(60, angleB, 0.01);
			Assert::AreEqual(60, angleC, 0.01);
		}
	};
}