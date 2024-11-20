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
			Assert::AreEqual("Equilateral triangle", result);
		}
	};
}
