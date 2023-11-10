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
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void GetAnglesFromSides(int side1, int side2, int side3, float buffer[]);

namespace PolygonChekcerUnitTesting {
	TEST_CLASS(PolygonChekcerUnitTesting) {
	public:
		
		//Distance() Tests
		TEST_METHOD(DistanceTest) {
			Vector2 center = { 1, 1 };
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 0, 2 };

			float d1 = Distance(v1, center);
			float d2 = Distance(v2, center);

			Assert::AreEqual(d1, d2);
		}
		TEST_METHOD(DistanceWithNegativePoints) {
			Vector2 center = { 0, 0 };
			Vector2 v1 = { -1, 0 };
			Vector2 v2 = { 0, -1 };

			float d1 = Distance(v1, center);
			float d2 = Distance(v2, center);

			Assert::AreEqual(d1, d2);
		}
		TEST_METHOD(DistanceHalfHalf) {
			Vector2 center = { 0, 0 };
			Vector2 v1 = { 0, -3 };
			Vector2 v2 = { 3, 0 };

			float d1 = Distance(v1, center);
			float d2 = Distance(v2, center);

			Assert::AreEqual(d1, d2);
		}

		//IsRectangle() Tests
		TEST_METHOD(RectangleTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 0, 4 };
			Vector2 v3 = { 4, 0 };
			Vector2 v4 = { 4, 4 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(true, isRectangle);
		}
		TEST_METHOD(Allpositive) {
			Vector2 v1 = { 1, 1 };
			Vector2 v2 = { 1, 4 };
			Vector2 v3 = { 4, 1 };
			Vector2 v4 = { 4, 4 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(true, isRectangle);
		}
		TEST_METHOD(Halfandhalf) {
			Vector2 v1 = { -2, -2 };
			Vector2 v2 = { -2, 4 };
			Vector2 v3 = { 4, -2 };
			Vector2 v4 = { 4, 4 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(true, isRectangle);
		}
		TEST_METHOD(RectangleMishap) {
			Vector2 v1 = { -2, -2 };
			Vector2 v2 = { 4, -2 };
			Vector2 v3 = { -2, 4 };
			Vector2 v4 = { 4, 4 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(false, isRectangle);
		}
		TEST_METHOD(RectangleFailure) {
			Vector2 v1 = { -1, -2 };
			Vector2 v2 = { -2, 4 };
			Vector2 v3 = { 4, -1 };
			Vector2 v4 = { 4, 4 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(false, isRectangle);
		}
		TEST_METHOD(Allnegative) {
			Vector2 v1 = { -1, -1 };
			Vector2 v2 = { -3, -1 };
			Vector2 v3 = { -1, -3 };
			Vector2 v4 = { -3, -3 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(true, isRectangle);
		}
		TEST_METHOD(AllSame) {
			Vector2 v1 = { 1, 1 };
			Vector2 v2 = { 1, 1 };
			Vector2 v3 = { 1, 1 };
			Vector2 v4 = { 1, 1 };

			bool isRectangle = IsRectangle(v1, v2, v3, v4);

			Assert::AreEqual(false, isRectangle);
		}

		//GetRectangleArea Tests
		TEST_METHOD(AreaTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float area = GetRectangleArea(v1, v2, v3, v4);

			Assert::AreEqual(16.f, area);
		}
		TEST_METHOD(NegativaArea) {
			Vector2 v1 = { -1, -1 };
			Vector2 v2 = { -3, -1 };
			Vector2 v3 = { -1, -3 };
			Vector2 v4 = { -3, -3 };

			float area = GetRectangleArea(v1, v2, v3, v4);

			Assert::AreEqual(16.f, area);
		}

		//GetPerimeter() tests
		TEST_METHOD(PerimeterTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float perimeter = GetPerimeter(v1, v2, v3, v4);

			Assert::AreEqual(16.f, perimeter);
		}

		//analyzeTriangle() tests
		TEST_METHOD(AnalyzeTriangle) {
			int side1 = 5;
			int side2 = 5;
			int side3 = 4;

			char* result = analyzeTriangle( side1, side2, side3);

			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(AnalyzeTriangle2) {
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Equilateral triangle", result);
		}
		TEST_METHOD(AnalyzeTriangle3) {
			int side1 = 1;
			int side2 = 3;
			int side3 = 4;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Scalene triangle", result);
		}
		TEST_METHOD(NegativPoint) {
			int side1 = -1;
			int side2 = 3;
			int side3 = 4;

			char* result = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual("Not a triangle", result);
		}

	};
}