#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "rectangle.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForRectangle
{
	TEST_CLASS(UnitTestForRectangle)
	{
	public:
		
        // Test case to calulate the area of rectangle
        TEST_METHOD(TestCalculateArea)
        {
            // Arrange
            int length = 5;
            int breadth = 10;

            // Act
            int area = calculate_area(length, breadth);

            // Assert
            Assert::AreEqual(50, area); // 5 * 10 = 50
        }

        //test case to calculate the perimeter of rectangle

        TEST_METHOD(TestCalculatePerimeter)
        {
            int length = 12;
            int breadth = 5;

            int perimeter = calculate_perimeter(length, breadth);

            Assert::AreEqual(34, perimeter); // 2(l+b) = 2(12+5) = 2 * 17 = 34
        }

	};
}
