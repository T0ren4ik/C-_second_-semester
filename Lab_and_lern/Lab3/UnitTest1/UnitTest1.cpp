#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(sin_x(30),sin(30), 1e-5);
			Assert::IsTrue((sin_x(320) - sin(320)) < 1e-5);
			Assert::IsTrue((sin_x(0) - sin(0)) < 1e-5);


			Assert::IsTrue((e_x(0.5) - exp(0.5)) < 1e-5);
			Assert::IsTrue((e_x(1) - exp(1)) < 1e-5);
			Assert::IsTrue((e_x(20) - exp(20)) < 1e-5);

		}
	};
}
