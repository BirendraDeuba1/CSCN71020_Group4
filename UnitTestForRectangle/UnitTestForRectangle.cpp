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
		
        TEST_METHOD(TestCalculateArea)
        {
            // Arrange
            int width = 5;
            int height = 10;

            // Act
            int area = calculate_area(width, height);

            // Assert
            Assert::AreEqual(50, area); // 5 * 10 = 50
        }
	};
}
