#include "rectangle.h"
#include "math.h"

double calculate_area(double points[4][2]) {
    // Calculate lengths of two adjacent sides
    double side1 = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
    double side2 = distance(points[1][0], points[1][1], points[2][0], points[2][1]);

    return side1 * side2;
}
    // Function to calculate perimeter based on the four points (assuming a rectangle)
double calculate_perimeter(double points[4][2]) {
        // Calculate lengths of two adjacent sides.
        double side1 = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
        double side2 = distance(points[1][0], points[1][1], points[2][0], points[2][1]);
        // i removed side3 , side4 from here since it doesn't affect the calculation for getting the perimeter of rectangle.

        // Perimeter of rectangle = 2* (l +b) 
        return 2 * (side1 + side2);
    }
// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int are_perpendicular(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4) {
    // Vectors: (x2 - x1, y2 - y1) and (x4 - x3, y4 - y3)
    double vector1_x = x2 - x1;
    double vector1_y = y2 - y1;
    double vector2_x = x4 - x3;
    double vector2_y = y4 - y3;
    // Dot product of the vectors (should be 0 for perpendicular lines)
    double dot_product = vector1_x * vector2_x + vector1_y * vector2_y;
    return (fabs(dot_product) < 1e-9);  // using a small threshold instead of exact zero
}

// Function to check if the points form a rectangle
int is_rectangle(double points[4][2]) {
    // Calculate the lengths of the sides
    double side1 = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
    double side2 = distance(points[1][0], points[1][1], points[2][0], points[2][1]);
    double side3 = distance(points[2][0], points[2][1], points[3][0], points[3][1]);
    double side4 = distance(points[3][0], points[3][1], points[0][0], points[0][1]);

    // Check for degenerate rectangle (if any side has zero length)
    if (side1 == 0 || side2 == 0 || side3 == 0 || side4 == 0) {
        return 0;  // Not a valid rectangle
    }

    // Check for opposite sides being equal (necessary condition for rectangle)
    if (!(side1 == side3 && side2 == side4)) {
        return 0;  // Not a rectangle
    }

    // Check if the four angles are 90 degrees (using perpendicularity check)
    if (are_perpendicular(points[0][0], points[0][1], points[1][0], points[1][1],
        points[1][0], points[1][1], points[2][0], points[2][1]) &&
        are_perpendicular(points[1][0], points[1][1], points[2][0], points[2][1],
            points[2][0], points[2][1], points[3][0], points[3][1]) &&
        are_perpendicular(points[2][0], points[2][1], points[3][0], points[3][1],
            points[3][0], points[3][1], points[0][0], points[0][1]) &&
        are_perpendicular(points[3][0], points[3][1], points[0][0], points[0][1],
            points[0][0], points[0][1], points[1][0], points[1][1])) {
        return 1;  // It's a rectangle
    }

    return 0;  // Not a rectangle

}

