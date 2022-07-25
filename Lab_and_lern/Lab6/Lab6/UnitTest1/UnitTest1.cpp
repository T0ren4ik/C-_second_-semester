#include "pch.h"
#include "CppUnitTest.h"
#include "D:\C++\Lab_and_lern\Lab6\Lab6\Lab6\Header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Задание 5
			{
				int i;
				int n = 0;
				int* A = 0;
				{
					int val[] = { 1, 2, 3, 4 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				del_double(A, n);
				int TM[] = { 1, 2, 3, 4 };

				for (i = 0; i < n; i++) {
					Assert::AreEqual(A[i], TM[i], 1e-5);
				}
				delete[] A; A = nullptr;

				//===========================================
				{
					int val[] = { 1, 2, 2, 3 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				del_double(A, n);
				int TM1[] = { 1, 2, 3 };

				for (i = 0; i < n; i++) {
					Assert::AreEqual(A[i], TM1[i], 1e-5);
				}
				delete[] A; A = nullptr;

				//===========================================

				{
					int val[] = { 1, 2, 3, 3 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}
				del_double(A, n);
				int TM2[] = { 1, 2, 3 };

				for (i = 0; i < n; i++) {
					Assert::AreEqual(A[i], TM2[i], 1e-5);
				}
				delete[] A; A = nullptr;

				//===========================================

				{
					int val[] = { 1, 1, 2, 3 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}
				del_double(A, n);
				int TM3[] = { 1, 2, 3 };

				for (i = 0; i < n; i++) {
					Assert::AreEqual(A[i], TM3[i], 1e-5);
				}
				delete[] A; A = nullptr;

				//===========================================

				{
					int val[] = { 3, 3, 3, 3 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}
				del_double(A, n);
				int TM4 = 3;

				for (i = 0; i < n; i++) {
					Assert::AreEqual(A[i], TM4, 1e-5);
				}
				delete[] A; A = nullptr;
			}

			// Задание 4
			{
				int i;
				int n = 0;
				int* A = 0;
				{
					int val[] = { 1, 2, 3, 4 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}
				int nn = 0;
				int* B = 0;
				B = new_array(A, n, 10);
				int TM[] = { 1, 2, 10, 3, 4 };

				for (i = 0; i < nn; i++) {
					Assert::AreEqual(B[i], TM[i], 1e-5);
				}
				delete[] A; A = nullptr;
				delete[] B; B = nullptr;
				//======================================

				{
					int val[] = { 1, 2, 3};
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				B = new_array(A, n, 10);

				int TM1[] = { 1, 2, 10, 3 };

				for (i = 0; i < nn; i++) {
					Assert::AreEqual(B[i], TM1[i], 1e-5);
				}
				delete[] A; A = nullptr;
				delete[] B; B = nullptr;



			}

			// Задание 7
			{
				int i;
				int n = 0;
				int* A = 0;
				{
					int val[] = { 0, 0, 0, 0 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				Assert::IsTrue(F(A, n, zero));
			
				delete[] A; A = nullptr;

				//======================================

				{
					int val[] = { 2, 4, 6, 8 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				Assert::IsTrue(F(A, n, chet));

				delete[] A; A = nullptr;

				//======================================

				{
					int val[] = { 2, 4, 7, 8 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				Assert::IsFalse(F(A, n, chet));

				delete[] A; A = nullptr;


			}

			// Задание 8
			{
				int i;
				int n = 0;
				int* A = 0;
				{
					int val[] = { 1, 2, 3, 4 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				Assert::IsTrue(T_F(A, n, vozr) == -1);

				delete[] A; A = nullptr;

				//===============================================
				{
					int val[] = { 3, 2, 3, 4 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				Assert::IsTrue(T_F(A, n, vozr) == 1);

				delete[] A; A = nullptr;

				//===============================================
				{
					int val[] = { 2, 2, 3, 4 };
					n = int(sizeof(val) / sizeof(int));
					A = new int[sizeof(val) / sizeof(int)];
					for (i = 0; i < n; ++i) {
						A[i] = val[i];
					}
				}

				Assert::IsTrue(T_F(A, n, el_equivalent) == 1);

				delete[] A; A = nullptr;
			}
		}
	};
}
	