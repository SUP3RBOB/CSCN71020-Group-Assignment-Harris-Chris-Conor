#include "vector.h"
#include <math.h>

float Distance(Vector2 start, Vector2 end) {
	float dx = start.x - end.x;
	float dy = start.y - end.y;
	return sqrtf((dx * dx) + (dy * dy));
}

bool IsRectangle(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4) {
	if (VectorAreEqual(v1, v2) == true && VectorAreEqual(v2, v3) == true && VectorAreEqual(v3, v4))
		return false;
	Vector2 center;
	center.x = (v1.x + v2.x + v3.x + v4.x) / 4.f;
	center.y = (v1.y + v2.y + v3.y + v4.y) / 4.f;
	
	float corner1 = Distance(v1, center);
	float corner2 = Distance(v2, center);
	float corner3 = Distance(v3, center);
	float corner4 = Distance(v4, center);

	return corner1 == corner2 && corner2 == corner3 && corner3 == corner4;
}

float GetRectangleArea(float side1, float side2) {
	float area = side1 * side2;
	if (area < 0) {
		area *= -1;
	}
	return area;
}

float GetPerimeter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4) {
	float s1 = Distance(v1, v2);
	float s2 = Distance(v2, v3);
	float s3 = Distance(v3, v4);
	float s4 = Distance(v4, v1);

	return s1 + s2 + s3 + s4;
}

Vector2 SetVector(float x, float y) {
	Vector2 v = { 0 };
	v.x = x;
	v.y = y;
	return v;
}

bool VectorAreEqual(Vector2 v1, Vector2 v2) {
	if (v1.x == v2.x && v1.y == v2.y)
		return true;
	
	return false;
}