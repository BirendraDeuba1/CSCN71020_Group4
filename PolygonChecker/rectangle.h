#pragma once

// Function declarations
double calculate_area(double points[4][2]);  // Function to calculate the area
double calculate_perimeter(double points[4][2]); // Function to calculate the perimeter
double distance(double x1, double y1, double x2, double y2);  // Function to calculate distance
int are_perpendicular(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4);  // Function to check perpendicularity
int is_rectangle(double points[4][2]);  // Function to check if the points form a rectangle