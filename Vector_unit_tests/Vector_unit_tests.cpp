#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
#include <math.h>

extern "C" typedef struct { float x; float y; } Vector2;
extern "C" float Distance(Vector2 start, Vector2 end);
extern "C" bool IsRectangle(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
extern "C" float GetRectangleArea(float side1, float side2);
extern "C" float GetPerimeter(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4);
extern "C" Vector2 SetVector(float x, float y);
extern "C" bool VectorAreEqual(Vector2 v1, Vector2 v2);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vectorunittests
{
	TEST_CLASS(Vectorunittests)
	{
	public:
		
		//Distance() Tests
		TEST_METHOD(DistanceTest) {	//harris
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
		TEST_METHOD(RectangleTest) {	//harris
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

			Assert::AreNotEqual(false, isRectangle);
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

		//GetRectangleArea Tests  2
		TEST_METHOD(AreaTest) {		//harris
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float area = GetRectangleArea(Distance(v1, v2), Distance(v2, v3));

			Assert::AreEqual(16.f, area);
		}
		TEST_METHOD(NegativaArea) {
			Vector2 v1 = { -1, -1 };
			Vector2 v2 = { -3, -1 };
			Vector2 v3 = { -1, -3 };
			Vector2 v4 = { -3, -3 };

			float area = GetRectangleArea(Distance(v1, v2), Distance(v2, v3));

			Assert::AreEqual(5.6568542f, area);
		}

		//GetPerimeter() tests
		TEST_METHOD(PerimeterTest) {	//harris
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float perimeter = GetPerimeter(v1, v2, v3, v4);

			Assert::AreEqual(16.f, perimeter);
		}
		/*
		TEST_METHOD(PerimeterTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float perimeter = GetPerimeter(v1, v2, v3, v4);

			Assert::AreEqual(16.f, perimeter);
		}
		TEST_METHOD(PerimeterTest) {
			Vector2 v1 = { 0, 0 };
			Vector2 v2 = { 4, 0 };
			Vector2 v3 = { 4, 4 };
			Vector2 v4 = { 0, 4 };

			float perimeter = GetPerimeter(v1, v2, v3, v4);

			Assert::AreEqual(16.f, perimeter);
		}
		*/
		// SetVector tests	Connor
		TEST_METHOD(equalx_SetVector) {
			float x = 1.0, y = 1.0;
			Vector2 a = { 0 };
			a.x = 1.0, a.y = 1.0;
			Vector2 b = SetVector(x, y);
			Assert::AreEqual(a.x, b.x);
		}
		TEST_METHOD(equaly_SetVector) {
			float x = 1.0, y = 1.0;
			Vector2 a = { 0 };
			a.x = 1.0, a.y = 1.0;
			Vector2 b = SetVector(x, y);
			Assert::AreEqual(a.y, b.y);
		}
		TEST_METHOD(negativex_SetVector) {
			float x = -4.0, y = 3.0;
			Vector2 a = { 0 };
			a.x = -4.0, a.y = 3.0;
			Vector2 b = SetVector(x, y);
			Assert::AreEqual(a.x, b.x);
		}
		TEST_METHOD(negativey_SetVector) {
			float x = 4.0, y = -3.0;
			Vector2 a = { 0 };
			a.x = 4.0, a.y = -3.0;
			Vector2 b = SetVector(x, y);
			Assert::AreEqual(a.x, b.x);
		}
		TEST_METHOD(notequalx_SetVector) {
			float x = -9.0, y = 3.0;
			Vector2 a = { 0 };
			a.x = -4.0, a.y = 3.0;
			Vector2 b = SetVector(x, y);
			Assert::AreNotEqual(a.x, b.x);
		}
		TEST_METHOD(notequaly_SetVector) {
			float x = -4.0, y = 3.0;
			Vector2 a = { 0 };
			a.x = -4.0, a.y = 4.0;
			Vector2 b = SetVector(x, y);
			Assert::AreNotEqual(a.y, b.y);
		}

		// VectorAreEqual tests		Connor
		TEST_METHOD(equal_VectorAreEqual) {
			float x = -4.0, y = 3.0, k = -4.0, l = 3.0;
			Vector2 a = { 0 }, b = { 0 };
			a.x = x, a.y = y, b.x = k, b.y = l;
			Assert::AreEqual(true, VectorAreEqual(a, b));
		}
		TEST_METHOD(notequal_VectorAreEqual) {
			float x = -4.0, y = 70.0, k = -4.0, l = 3.0;
			Vector2 a = { 0 }, b = { 0 };
			a.x = x, a.y = y, b.x = k, b.y = l;
			Assert::AreNotEqual(true, VectorAreEqual(a, b));
		}
	};
}
