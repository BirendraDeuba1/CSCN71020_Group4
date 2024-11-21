#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

// implementation of triangle file
#define PI 3.14

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

void TriangleAngles(int a, int b, int c) {

	double angleA, angleB, angleC;
	angleA = acos((b * b + c * c - a * a) / (2.0 * b * c)) * (180.0 / PI);//To calculate angle we use 
	//cos(A) = b^2+c^2-a^2 / 2bc - cosine law
	//and then convert result to degree using
	// 180/PI or 3.14

	angleB = acos((a * a + c * c - b * b) / (2.0 * a * c)) * (180.0 / PI);

	angleC = 180.0 - angleA - angleB; // Sum of angles in a triangle is 180 degrees

	printf_s("The angles of the triangle are:\n");
	printf_s("Angle A: %f degrees\n", angleA);
	printf_s("Angle B: %f degrees\n", angleB);
	printf_s("Angle C: %f degrees\n", angleC);
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}
