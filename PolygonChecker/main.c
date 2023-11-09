#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "vector.h"

int side = 0;

int main() {

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice) {
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);

			float angles[3] = {-1, -1, -1};
			GetAnglesFromSides(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], angles);
			printf("The angles of the triangle are: %f, %f, %f\n", angles[0], angles[1], angles[2]);

			break;
		case 0:
			continueProgram = false;
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			Vector2 vectors[4];
			float x, y;
			for (int i = 0; i < 4; i++) {
				printf_s("Please enter x: ");
				scanf_s("%lf", &x);
				printf_s("Please enter y: ");
				scanf_s("%lf", &y);
				vectors[i] = setVector(&x, &y);
			}
			if (IsRectangle(vectors[1], vectors[2], vectors[3], vectors[4])) {
				printf("it is a rectangle");
			}
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
	printf_s("2. Rectangle\n");
	printf_s("1. Triangle\n");
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

Vector2 setVector(float* x, float* y) {
	Vector2 v = { 0 };
	v.x = *x;
	v.y = *y;
	return v;
}