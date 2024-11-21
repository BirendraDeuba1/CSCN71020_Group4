#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"

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

    int input;
    int scannedValues;
    printf("Enter menu option number :\n");
    do {
        scannedValues = scanf_s("%i", &input);
        int buf;
        while ((buf = getchar()) != '\n' && buf != EOF);
    } while (scannedValues != 1);
    return input;
}

bool Validity(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}


