#include "pch.h"
#include "CppUnitTest.h"
#include "..\Individ_3_Tregubov_5gr\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(good_plus_des_total_number("123"));
			Assert::IsTrue(good_plus_des_total_number("234123"));
			Assert::IsTrue(good_plus_des_total_number("0"));
			Assert::IsFalse(good_plus_des_total_number("-123"));
			Assert::IsFalse(good_plus_des_total_number("12asda3"));
			Assert::IsFalse(good_plus_des_total_number(""));

		}
	};
}
