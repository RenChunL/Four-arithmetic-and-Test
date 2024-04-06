#include "pch.h"
#include "CppUnitTest.h"
#include"C:\Users\任春林\source\repos\ruanjian2\源.cpp"
#include <iostream>
#include <vector>
#include <cassert>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			for (int i = 0; i < 100; ++i) {
				string expression = generateFirstGradeExpression();
				int result = evaluateExpression(expression);
				assert(result >= 0 && result <= 20);
			}

		}
		TEST_METHOD(TestMethod2)
		{

			for (int i = 0; i < 100; ++i) {
				string expression = generateSecondGradeExpression();
				int result = evaluateExpression(expression);
				assert(result >= 0 && result <= 50);
			}

		}
		TEST_METHOD(TestMethod3)
		{

			for (int i = 0; i < 100; ++i) {
				string expression = generateThirdGradeExpression();
				int result = evaluateExpression(expression);
				assert(result >= 0 && result <= 1000000000);
			}

		}
		TEST_METHOD(TestMethod4)
		{

			for (int i = 0; i < 100; ++i) {
				string expression = generateFourthToSixthGradeExpression();
				int result = evaluateExpression(expression);
				assert(result >= 0);
			}

		}
		TEST_METHOD(TestMethod5)
		{

			for (int grade = 1; grade <= 6; ++grade) {
				for (int count = 1; count <= 10; ++count) {
					generateExercises(grade, count);
				}
			}

		}
	};
}
