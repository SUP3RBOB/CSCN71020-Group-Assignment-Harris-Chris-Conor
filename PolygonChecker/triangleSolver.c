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
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void GetAnglesFromSides(int side1, int side2, int side3, float buffer[]) {
	float pi = 4.f * atanf(1.f);
	float s = (side1 + side2 + side3) / 2.f;
	float area = sqrtf(s * (s - side1) * (s - side2) * (s - side3));

	float r = (side1 * side2 * side3) / (4.f * area);
	
	float angle1 = (180.f / pi) * asinf(side1 / (2.f * r));
	float angle2 = (180.f / pi) * asinf(side2 / (2.f * r));
	float angle3 = (180.f / pi) * asinf(side3 / (2.f * r));

	buffer[0] = angle1;
	buffer[1] = angle2;
	buffer[2] = angle3;
}