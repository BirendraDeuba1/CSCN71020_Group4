#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "main.h"
#include "triangleSolver.h"
#define PI 3.14

int side = 0;

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice)
        {
        case 1: 
        {
            printf_s("Triangle selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            //printf_s("! %d\n", triangleSidesPtr[0]);
            char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            printf_s("%s\n", result);
            break;
        }

        case 2: {
            // Calculate and display triangle angles
            printf_s("Triangle Angle Calculation selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);

            if (Validity(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])) {
                TriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            }
            else {
                printf_s("Cannot calculate angles. The sides do not form a valid triangle.\n");
            }
            break;
        }

        case 0:
            continueProgram = false;
            printf_s("Exiting the program. Goodbye!\n");
            break;

        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}
  

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Calculate Triangle Angles\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number: ");
    scanf_s("%1o", &shapeChoice);

    return shapeChoice;
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
    return (a + b > c) && (a + c > b) && (b + c > a);
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