#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side2 == side3 && side2 != side1) ||
		side1 == side3 && side1 != side2)
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void GetAnglesFromSides(int side1, int side2, int side3, float buffer[]) {

	float angle1 = acosf((((side1 * side1) + (side2 * side2) - (side3 * side3)) / (2 * (side1 * side2))));
	float angle2 = acosf((((side1 * side1) + (side3 * side3) - (side2 * side2)) / (2 * (side1 * side3))));
	float angle3 = acosf((((side3 * side3) + (side2 * side2) - (side1 * side1)) / (2 * (side3 * side2))));

	buffer[0] = angle1;
	buffer[1] = angle2;
	buffer[2] = angle3;

}