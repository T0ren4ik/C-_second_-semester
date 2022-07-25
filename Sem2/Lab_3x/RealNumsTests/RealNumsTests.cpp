#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_3x\real.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RealNumsTests
{
	TEST_CLASS(BaseTests)
	{
	public:
		//  Тесты конструкторов - по сути, тесты normalize()
		TEST_METHOD(Constructors)
		{
			//  Тестируем приведение к нормальному виду и конструкторы
			//  Вывод покажет, какой из операторов дал срабатывание
			real num0;
			Assert::IsTrue(num0.mnt() == 0, L"Case 0 failed");
			Assert::IsTrue(num0.exp() == 0, L"Case 1 failed");

			real num1(0, 10);
			Assert::IsTrue(num1.mnt() == 0, L"Case 2 failed");
			Assert::IsTrue(num1.exp() == 0, L"Case 3 failed");

			real num2(-10, 10);
			Assert::IsTrue(num2.mnt() == -1, L"Case 4 failed");
			Assert::IsTrue(num2.exp() == 11, L"Case 5 failed");

			real num3(-1, 0);
			Assert::IsTrue(num3.mnt() == -1, L"Case 6 failed");
			Assert::IsTrue(num3.exp() == 0, L"Case 7 failed");

			real num4(-1000000, 144);
			Assert::IsTrue(num4.mnt() == -1, L"Case 6 failed");
			Assert::IsTrue(num4.exp() == 150, L"Case 7 failed");
		}

		TEST_METHOD(ComparisonTests)
		{
			//  Тестируем приведение к нормальному виду
			//  Впрочем, это и в первом блоке тестов работает

			//  Оператор "меньше" и "меньше либо равно" тестируем
			Assert::IsTrue(real(-1, 100) < real(1, -100), L"Case 0 failed");
			Assert::IsTrue(real(-1, 0) < real(), L"Case 1 failed");
			Assert::IsTrue(real(-0, 100) < real(1, 0), L"Case 2 failed");
			Assert::IsTrue(real(201, 0) < real(30, 1), L"Case 3 failed");
			Assert::IsTrue(real(1, 1000) < real(1, 1001), L"Case 4 failed");
			Assert::IsTrue(real(17, 0) < real(18, 0), L"Case 5 failed");
			Assert::IsTrue(real(17, 2) < real(1701, 0), L"Case 6 failed");
			Assert::IsTrue(real(-17, 10000) < real(1, 100000), L"Case 7 failed");

			//  Оператор "больше" и "больше либо равно" тестируем
			Assert::IsTrue(real(1, 101) > real(1, 100), L"Case 8 failed");
			Assert::IsTrue(real() >= real(0, 0), L"Case 9 failed");
			Assert::IsTrue(real(-0, 100) <= real(0, -1), L"Case 10 failed");
			Assert::IsTrue(real(30, 1) > real(202, 0), L"Case 11 failed");
			Assert::IsTrue(real(1, 1001) >= real(1, 1000), L"Case 12 failed");
			Assert::IsTrue(real(18, 1) >= real(180, 0), L"Case 13 failed");
			Assert::IsTrue(real(10000, -2) >= real(100, 0), L"Case 14 failed");
			Assert::IsTrue(real(1, 10000) >= real(-17, 100000), L"Case 15 failed");
		}

		TEST_METHOD(ComparisonTests2)
		{
			//  Операторs == и !=  тестируем
			Assert::IsTrue(real(-1, 100) != real(1, -100), L"Case 0 failed");
			Assert::IsTrue(real(-1, 0) != real(), L"Case 1 failed");
			Assert::IsTrue(real(0, 0) == real(0, 2), L"Case 2 failed");
			Assert::IsTrue(real(2010, 0) == real(201, 1), L"Case 3 failed");
			Assert::IsTrue(real(1, 1000) != real(1, 1001), L"Case 4 failed");
			Assert::IsTrue(real(17, 0) != real(18, 0), L"Case 5 failed");
			Assert::IsTrue(real(17, 2) != real(1701, 0), L"Case 6 failed");
			Assert::IsTrue(real(-17, 10000) != real(1, 100000), L"Case 7 failed");

			//  Оператор "больше" и "больше либо равно" тестируем
			Assert::IsTrue(real(1, 101) > real(1, 100), L"Case 8 failed");
			Assert::IsTrue(real() >= real(0, 0), L"Case 9 failed");
			Assert::IsTrue(real(-0, 100) < real(1, 0), L"Case 10 failed");
			Assert::IsTrue(real(201, 0) < real(30, 1), L"Case 11 failed");
			Assert::IsTrue(real(1, 1000) < real(1, 1001), L"Case 12 failed");
			Assert::IsTrue(real(17, 0) < real(18, 0), L"Case 13 failed");
			Assert::IsTrue(real(17, 2) < real(1701, 0), L"Case 14 failed");
			Assert::IsTrue(real(-17, 10000) < real(1, 100000), L"Case 15 failed");
		}
	};
	TEST_CLASS(ComplexTests)
	{
	public:
		//  Тесты умножения
		TEST_METHOD(MultTests)
		{
			real num0 = real(5, 10) * real(3, 11);
			Assert::IsTrue(num0.mnt() == 15 && num0.exp() == 21, L"Case 0 failed");
			real num1 = real(-5, 10) * real(3, 11);
			Assert::IsTrue(num1.mnt() == -15 && num1.exp() == 21, L"Case 1 failed");
			real num2 = real(-1000, 10) * real(1, 11);
			Assert::IsTrue(num2.mnt() == -1 && num2.exp() == 24, L"Case 2 failed");
		}

		//  Тесты деления
		TEST_METHOD(DivisionTests)
		{
			real num0 = real(5, 10) / real(3, 11);
			Assert::IsTrue(abs(num0.to_double() - double(5) / 30) < 0.00000001, L"Case 0 failed");
			real num1 = real(1, 10) / real(3, 10);
			Assert::IsTrue(abs(num1.to_double() - double(1) / 3) < 0.00000001, L"Case 1 failed");
			real num2 = real(-1000, 10) * real(1, 11);
			Assert::IsTrue(num2.mnt() == -1 && num2.exp() == 24, L"Case 2 failed");
		}
	};
}
