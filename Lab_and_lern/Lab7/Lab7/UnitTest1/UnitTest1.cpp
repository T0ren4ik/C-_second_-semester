#include "pch.h"
#include "CppUnitTest.h"
#include "..\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[] = { 1, -2, 0, 4 };
			int b[] = { 3, 4, 8, -12 };
			int n = sizeof(a) / sizeof(int);
			Assert::AreEqual(rec_sum(a, n), 3, 1e-5);
			Assert::AreEqual(rec_sum(b, n), 3, 1e-5);

			//====================== 2 ===================

			Assert::AreEqual(F_count(a, n, pos), 2, 1e-5);
			Assert::AreEqual(F_count(b, n, chet), 3, 1e-5);
			Assert::AreEqual(F_count(b, n, pos), 3, 1e-5);

			//====================== 3 ===================

			Assert::AreEqual(rec_max_el_seg(a, a + 3), 4, 1e-5);
			Assert::AreEqual(rec_max_el_seg(b, b + 3), 8, 1e-5);
			Assert::AreEqual(rec_max_el_seg(b, b + 1), 4, 1e-5);


			//====================== 4 ===================

			Assert::IsFalse(rec_zero_not(a, n));
			Assert::IsTrue(rec_zero_not(b, n));

			//====================== 5 ===================


			//int c[] = { 1, 0 ,0 };
			//int n2 = sizeof(c) / sizeof(int);

			//try {
			//	Assert::AreEqual(ratio_mud_sum(c, n2), 0., 1e-5);
			//}
			//catch (const char*) {
			//	Assert::IsTrue(true); //问
			//}
			//catch (int) {
			//	Assert::IsTrue(true); //问
			//}

			//////==========================================================

			//try {
			//	Assert::AreEqual(ratio_mud_sum(b, n), 0., 1e-5);
			//}
			//catch (const char*) {
			//	Assert::IsTrue(true); //问
			//}
			//catch (int) {
			//	Assert::IsTrue(true); //问
			//}

			//////==========================================================

			//try {
			//	Assert::AreEqual(ratio_mud_sum(a, n), -0.25, 1e-5);
			//}
			//catch (const char*) {
			//	Assert::IsTrue(true); //问
			//}
			//catch (int) {
			//	Assert::IsTrue(true); //问
			//}
		}
	};
}
