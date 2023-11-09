#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" typedef struct { float x; float y; } Vector2;
extern "C" float Distance(Vector2 start, Vector2 end);
extern "C" bool IsRectangle(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
extern "C" float GetRectangleArea(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
extern "C" float GetPerimeter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);

namespace PolygonChekcerUnitTesting {
	TEST_CLASS(PolygonChekcerUnitTesting) {
	public:
		
		TEST_METHOD(DistanceTest) {
			Vector2 center = { 1, 1 };
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 0, 2 };

			float d1 = Distance(v1, center);
			float d2 = Distance(v2, center);

			Assert::AreEqual(d1, d2);
		}

		TEST_METHOD(RectangleTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 0, 4 };
			Vector2 v3 = { 4, 0 };
			Vector2 v4 = { 4, 4 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(true, isRectangle);
		}

		TEST_METHOD(AreaTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float area = GetRectangleArea(v1, v2, v3, v4);

			Assert::AreEqual(16.f, area);
		}

		TEST_METHOD(PerimeterTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float perimeter = GetPerimeter(v1, v2, v3, v4);

			Assert::AreEqual(16.f, perimeter);
		}
	};
}
