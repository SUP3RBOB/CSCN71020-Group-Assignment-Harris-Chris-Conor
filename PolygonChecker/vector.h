#pragma once
#include <stdbool.h>

typedef struct {
	float x;
	float y;
} Vector2;

float Distance(Vector2 start, Vector2 end);
bool IsRectangle(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
float GetPerimeter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);