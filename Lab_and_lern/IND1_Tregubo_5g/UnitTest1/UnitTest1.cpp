#include "pch.h"
#include "CppUnitTest.h"
#include "../IND1_Tregubo_5g/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(LEN(123), 3, 1e-5);
			Assert::AreEqual(LEN(0), 1, 1e-5);

			Assert::AreEqual(count_square63(123), 0, 1e-5);
			Assert::AreEqual(count_square63(34), 1, 1e-5);

			Assert::AreEqual(sun_extreme(123, 5), 5, 1e-5);
			Assert::AreEqual(sun_extreme(99, 5), 18, 1e-5);

			Assert::AreEqual(square(5), 25, 1e-5);
			Assert::AreEqual(square(-5), 25, 1e-5);
			Assert::AreEqual(square(0), 0, 1e-5);

		}
	};
}
