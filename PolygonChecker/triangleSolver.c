#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"


// implementation of triangle file
#define PI 3.14159265358979323846			// this is more accurate for PI value to get accurate angle for traingle

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	// added this else if function to check for triangle inequality
	else if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1)) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

bool TriangleAngles(int a, int b, int c, double* angleA, double* angleB, double* angleC) {	// i change the this function into pointer for angle for more precise testing
	if (!Validity(a, b, c)) {		// added this function here to check the validity of triangle which main function lies in main.c 
		printf_s("Invalid triangle with sides: %d, %d, %d\n", a, b, c);
		return false; // Invalid triangle
	}
	// Check for validity of the triangle
	if (!angleA || !angleB || !angleC) {
		return false;	// make sure of valid pointer
	}
	*angleA = acos((double)(b * b + c * c - a * a) / (2.0 * b * c)) * (180.0 / PI);//To calculate angle we use 
	//cos(A) = b^2+c^2-a^2 / 2bc - cosine law
	//and then convert result to degree using
	// 180/PI or 3.14

	*angleB = acos((double)(a * a + c * c - b * b) / (2.0 * a * c)) * (180.0 / PI);

	*angleC = 180.0 - *angleA - *angleB; // Sum of angles in a triangle is 180 degrees

	return true;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

bool Validity(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return false;
	}
	if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
		return false;
	}
	return true;
}
