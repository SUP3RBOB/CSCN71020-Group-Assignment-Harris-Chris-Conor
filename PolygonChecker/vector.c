#include "vector.h"
#include <math.h>

float Distance(Vector2 start, Vector2 end) {
	float dx = start.x - end.x;
	float dy = start.y - end.y;
	return sqrtf((dx * dx) + (dy * dy));
}

bool IsRectangle(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4) {
	Vector2 center;
	center.x = (v1.x + v2.x + v3.x + v4.x) / 4.f;
	center.y = (v1.y + v2.y + v3.y + v4.y) / 4.f;
	
	float corner1 = Distance(v1, center);
	float corner2 = Distance(v2, center);
	float corner3 = Distance(v3, center);
	float corner4 = Distance(v4, center);

	return corner1 == corner2 && corner2 == corner3 && corner3 == corner4;
}

float GetPerimeter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4) {
	float s1 = Distance(v1, v2);
	float s2 = Distance(v2, v3);
	float s3 = Distance(v3, v4);
	float s4 = Distance(v4, v1);

	return s1 + s2 + s3 + s4;
}

