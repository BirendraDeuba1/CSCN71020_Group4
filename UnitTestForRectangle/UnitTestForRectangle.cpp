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

        // Test for degenerate rectangle (same point repeated)
        TEST_METHOD(TestDegenerateRectangle)
        {
            double degenerate_rectangle[4][2] = {
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0}
            };

            Assert::IsFalse(is_rectangle(degenerate_rectangle));  // Not a valid rectangle
            Assert::AreEqual(0.0, calculate_area(degenerate_rectangle), 0.001); // Area should be 0
            Assert::AreEqual(0.0, calculate_perimeter(degenerate_rectangle), 0.001); // Perimeter should be 0
        }

        // Test for very large rectangle
        TEST_METHOD(TestLargeRectangle)
        {
            double large_rectangle[4][2] = {
                {0, 0},
                {1000000, 0},
                {1000000, 500000},
                {0, 500000}
            };

            Assert::IsTrue(is_rectangle(large_rectangle));
            Assert::AreEqual(500000000000.0, calculate_area(large_rectangle), 0.001); // Area = length * width
            Assert::AreEqual(3000000.0, calculate_perimeter(large_rectangle), 0.001); // Perimeter = 2 * (length + width)
        }

        // Test for very small rectangle (coordinates with small decimal values)
        TEST_METHOD(TestSmallRectangle)
        {
            double small_rectangle[4][2] = {
                {0.1, 0.1},
                {1.1, 0.1},
                {1.1, 1.1},
                {0.1, 1.1}
            };

            Assert::IsTrue(is_rectangle(small_rectangle));
            Assert::AreEqual(1.0, calculate_area(small_rectangle), 0.001); // Small area
            Assert::AreEqual(4.0, calculate_perimeter(small_rectangle), 0.001); // Perimeter should be 4
        }

        // Test for square (special case of rectangle)
        TEST_METHOD(TestSquare)
        {
            double square[4][2] = {
                {0, 0},
                {4, 0},
                {4, 4},
                {0, 4}
            };

            Assert::IsTrue(is_rectangle(square));  // A square is also a rectangle
            Assert::AreEqual(16.0, calculate_area(square), 0.001); // Area = side^2
            Assert::AreEqual(16.0, calculate_perimeter(square), 0.001); // Perimeter = 4 * side
        }

        // Test for distance function with vertical line
        TEST_METHOD(TestVerticalDistance)
        {
            Assert::AreEqual(5.0, distance(0, 0, 0, 5), 0.001);  // Distance between two vertical points
        }

        // Test for distance function with horizontal line
        TEST_METHOD(TestHorizontalDistance)
        {
            Assert::AreEqual(7.0, distance(0, 0, 7, 0), 0.001);  // Distance between two horizontal points
        }

        // Test for perpendicular lines: horizontal and vertical
        TEST_METHOD(TestPerpendicularWithHorizontalVertical)
        {
            Assert::IsTrue(are_perpendicular(0, 0, 1, 0, 0, 0, 0, 1)); // Horizontal and Vertical lines
        }

        // Test for non-perpendicular lines
        TEST_METHOD(TestNonPerpendicular)
        {
            Assert::IsFalse(are_perpendicular(0, 0, 1, 1, 0, 0, 2, 2)); // Slanted lines
        }
    };
}
