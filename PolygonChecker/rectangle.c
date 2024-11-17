#include "rectangle.h"

int calculate_area(int length, int breadth) { //added the functionality to get the area of rectangle.
    return length * breadth ;
}

int calculate_perimeter(int length, int breadth) { //fixed the formula to get the perimeter of rectangle
    return 2*(length + breadth);
}