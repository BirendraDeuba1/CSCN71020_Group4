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
		
        TEST_METHOD(TestValidRectangle)
        {
            double rectangle[4][2] = {
                {0, 0},
                {4, 0},
                {4, 3},
                {0, 3}
            };

            Assert::IsTrue(is_rectangle(rectangle));
            Assert::AreEqual(12.0, calculate_area(rectangle), 0.001);
            Assert::AreEqual(14.0, calculate_perimeter(rectangle), 0.001);
        }

        TEST_METHOD(TestInvalidRectangle)
        {
            double not_rectangle[4][2] = {
                {0, 0},
                {4, 1},
                {3, 5},
                {1, 3}
            };

            Assert::IsFalse(is_rectangle(not_rectangle));
            // We can still test perimeter for non-rectangles
            Assert::AreNotEqual(0.0, calculate_perimeter(not_rectangle));
        }

        TEST_METHOD(TestDistanceFunction)
        {
            Assert::AreEqual(5.0, distance(0, 0, 3, 4), 0.001);
        }

        TEST_METHOD(TestPerpendicularLines)
        {
            Assert::IsTrue(are_perpendicular(0, 0, 1, 0, 1, 0, 1, 1));
            Assert::IsFalse(are_perpendicular(0, 0, 1, 1, 1, 1, 2, 1));
        }
    };
}
