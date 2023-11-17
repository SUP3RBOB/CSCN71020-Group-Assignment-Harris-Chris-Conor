#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
#include <math.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void GetAnglesFromSides(float side1, float side2, float side3, float buffer[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Triangleunittests
{
	TEST_CLASS(Triangleunittests)
	{
	public:
		
		//analyzeTriangle() tests
		TEST_METHOD(AnalyzeTriangle) {		// chris did all triangles
			int side1 = 5;
			int side2 = 5;
			int side3 = 4;

			char* result = analyzeTriangle(side1, side2, side3);

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

		//GetAnglesFromSides tests
		TEST_METHOD(isoGetAngle1FromSides) {
			float side1 = 5;
			float side2 = 5;
			float side3 = 4;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(47.156353f, buffer[0]);
		}
		TEST_METHOD(isoGetAngle2FromSides) {
			float side1 = 5;
			float side2 = 5;
			float side3 = 4;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(66.4218215f, buffer[1]);
		}
		TEST_METHOD(isoGetAngle3FromSides) {
			float side1 = 5;
			float side2 = 5;
			float side3 = 4;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(66.4218215f, buffer[2]);
		}
		TEST_METHOD(scaGetAngle1FromSides) {
			float side1 = 5;
			float side2 = 3;
			float side3 = 4;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(53.130100f, buffer[0]);
		}
		TEST_METHOD(scaGetAngle2FromSides) {
			float side1 = 5;
			float side2 = 3;
			float side3 = 4;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(36.869896f, buffer[1]);
		}
		TEST_METHOD(scaGetAngle3FromSides) {
			float side1 = 5;
			float side2 = 3;
			float side3 = 4;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(90.f, buffer[2]);
		}
		TEST_METHOD(equGetAngle1FromSides) {
			float side1 = 5;
			float side2 = 5;
			float side3 = 5;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(60.f, buffer[0]);
		}
		TEST_METHOD(equGetAngle2FromSides) {
			float side1 = 5;
			float side2 = 5;
			float side3 = 5;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(60.f, buffer[1]);
		}
		TEST_METHOD(equGetAngle3FromSides) {
			float side1 = 5;
			float side2 = 5;
			float side3 = 5;
			float buffer[3] = { 0 };

			GetAnglesFromSides(side1, side2, side3, buffer);

			Assert::AreEqual(60.f, buffer[2]);
		}
	};
}
