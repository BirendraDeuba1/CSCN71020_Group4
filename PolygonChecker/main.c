#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangle.h"

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

            // This one check for the valitdity of the triangle
            if (Validity(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])) {
                double angleA, angleB, angleC;
                bool anglesCalculated = TriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angleA, &angleB, &angleC);
                if (anglesCalculated) {
                    printf_s("The angles of the triangle are:\n");
                    printf_s("Angle A: %lf degrees\n", angleA);
                    printf_s("Angle B: %lf degrees\n", angleB);
                    printf_s("Angle C: %lf degrees\n", angleC);
                }
                else {
                    printf_s("Error while calulating the angle of traingle.\n");
                }
            }
            else {
                printf_s("Cannot calculate angles. The sides do not form a valid triangle.\n");
            }
            break;
        }
        case 3: {
            // Rectangle option
            printf_s("Rectangle selected.\n");
            double points[4][2];
            // Get the points for the rectangle
            for (int i = 0; i < 4; i++) {
                while (1) {
                    printf_s("Enter point %d (x,y): ", i + 1);
                    int valid_input = scanf_s("%lf,%lf", &points[i][0], &points[i][1]);
                    if (valid_input != 2) {
                        printf_s("Invalid input. Please enter the point as x,y (e.g., 2,3).\n");
                        while (getchar() != '\n'); // Clear the buffer
                    }
                    else {
                        break;
                    }
                }
            }
            // Check if the points form a rectangle
            if (is_rectangle(points)) {
                // Calculate the perimeter and area
                double side1 = distance(points[0][0], points[0][1], points[1][0], points[1][1]);
                double side2 = distance(points[1][0], points[1][1], points[2][0], points[2][1]);
                double perimeter = 2 * (side1 + side2);
                double area = side1 * side2;
                printf_s("The shape is a rectangle!\n");
                printf_s("Perimeter: %lf\n", perimeter);
                printf_s("Area: %lf\n", area);
            }
            else {
                printf_s("The points do not form a rectangle.\n");
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
    printf_s("3. Rectangle\n");
    printf_s("0. Exit\n");

    int input;
    int scannedValues;
    printf("Enter menu option number :\n");
    do {
        scannedValues = scanf_s("%i", &input);
        int buf;
        while ((buf = getchar()) != '\n' && buf != EOF);
        if (scannedValues != 1 || input < 0 || input > 3) {
            printf("Invalid choice. Please enter a number between 0 and 3.\n");
        }
    } while (scannedValues != 1 || input < 0 || input > 3);
    return input;
}

