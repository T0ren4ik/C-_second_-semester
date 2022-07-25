#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// ==========================1================================
			
			const int MAX_ROWS = 3;
			const int MAX_COLS = 3;
			matrix matr = {
				{1, 2, 3},
				{4, 0, 6},
				{7, 8, 0}
			};

				
			Assert::AreEqual(count_rows_cont_zero(matr, MAX_ROWS, MAX_COLS), 2, 1e-5);

			// ==========================2================================

			matrix matrT = {
				{1, 4, 7},
				{2, 0, 8},
				{3, 6, 0}
			};

			transposition(matr, 3, 3);

			for (size_t i = 0; i < MAX_ROWS; i++){
				for (size_t j = 0; j < MAX_COLS; j++){
					Assert::AreEqual(matr[i][j],matrT[i][j], 1e-5);
				}
			}

			// ==========================3================================

			int ROWS = 3, COLS = 3;
			matrix matrC = {
				{1, 2, 3},
				{2, 0, 4},
				{3, 4, 0}
			};

			Assert::IsFalse(symmetry_on_main(matr, 3, 3));
			Assert::IsTrue(symmetry_on_main(matrC, 3, 3));

			// ==========================4================================

			int matrD[2][3] = {
				{1, 2, 3},
				{3, 4, 0}
			};

			delete_n_Row(matrC, ROWS, COLS, 1);

			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					Assert::AreEqual(matrC[i][j], matrD[i][j], 1e-5);
				}
			}

			int matrDD[2][3] = {
				{2, 0, 8},
				{3, 6, 0}
			};
			ROWS = 3, COLS = 3;
			delete_n_Row(matrT, ROWS, COLS, 0);

			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					Assert::AreEqual(matrT[i][j], matrDD[i][j], 1e-5);
				}
			}

			// ==========================5================================

			const int m_col = 4;
			const int m_row = 3;

			matrix M = {
			 {1, 2, 3},
			 {4, 6, 6},
			 {10, 8, 9}
			};
			int a[] = { 3, 5, 7 };

			matrix M1 = {
			 {1, 2, 3},
			 {4, 6, 6},
			 {3, 5, 7},
			 {10, 8, 9}			 
			};

			add_p_rows(M, m_col, m_row, 2, a);

			for (int i = 0; i < m_col; i++) {
				for (int j = 0; j < m_row; j++) {
					Assert::AreEqual(M[i][j], M1[i][j], 1e-5);
				}
			}


			// ==========================6================================
			ROWS = 3, COLS = 3;
			matrix m = {
			{1, 2, 3},
			{4, 0, 6},
			{7, 8, 0}
			};

			int md[2][2] = {
			{1, 2},
			{7, 8}
			};

			delete_n_Row_m_col(m, ROWS, COLS, 1, 2);


			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLS; j++) {
					Assert::AreEqual(m[i][j], md[i][j], 1e-5);
				}
			}

			// ==========================7================================
			ROWS = 3, COLS = 3;
			matrix m1 = {
			{1, 2, 3},
			{4, 0, 6},
			{7, 8, 0}
			};

			matrix m2 = {
			{1, 2},
			{7, 8}
			};

			matrix m3 = {
			{1, 2, 3, 5},
			{4, 5, 6, 6},
			{7, 8, 11, 7},
			{7, 8, 9, 10}
			};


			Assert::AreEqual(determinate(m1, 3), 132, 1e-5);
			Assert::AreEqual(determinate(m2, 2), -6, 1e-5);
			Assert::AreEqual(determinate(m3, 4), -18, 1e-5);


		}
	};
}
