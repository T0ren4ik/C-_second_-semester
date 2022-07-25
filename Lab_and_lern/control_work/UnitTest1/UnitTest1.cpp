#include "pch.h"
#include "CppUnitTest.h"
#include "..\Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1){
			Assert::AreEqual(Sum_N(3), 1.36111, 1e-4);
			Assert::AreEqual(Sum_N(1), 1, 1e-4);
			Assert::AreEqual(Sum_N(15), 1.58044, 1e-4);
		}
	};
}
