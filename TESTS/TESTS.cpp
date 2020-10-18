#include "pch.h"
#include "CppUnitTest.h"
#include "..\CJ_LM\matrix.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TESTS
{
	TEST_CLASS(TESTS)
	{
	public:
		
		TEST_METHOD(TestTranpos)
		{
			matrix m1(2, 3, 1);
			matrix m2(1,1,0);
			m1.Get_m(0, 0) = 3.0;
			m1.Get_m(1, 0) = 2.0;
			m1.Get_m(0, 1) = 4.0;
			m2 = m1.transposition();
			Assert::AreEqual(m2.Get_m(0, 1), 2.0);
			Assert::AreEqual(m2.Get_m(1, 0), 4.0);
			
		}
		TEST_METHOD(testSum)
		{
			matrix m1(3, 3, 0);
			double counter = 1.0;
			for(int i = 0;i<3;i++)
				for (int j = 0; j < 3; j++)
				{
					m1.Get_m(i, j) = counter;
					counter++;
				}
			matrix m2(3, 3, 1);
			matrix m3(3, 3, 0);
			m3 = m1 + m2;
			counter = 2;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(m3.Get_m(i, j), counter);
					counter++;
				}
		}
		TEST_METHOD(testdeduct)
		{
			matrix m1(3, 3, 0);
			double counter = 1;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					m1.Get_m(i, j) = counter;
					counter++;
				}
			matrix m2(3, 3, 1);
			matrix m3(3, 3, 0);
			m3 = m1 - m2;
			counter = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(m3.Get_m(i, j), counter);
					counter++;
				}
		}
		TEST_METHOD(testcomp)
		{
			matrix m1(2, 2, 0);
			matrix m2(2, 2, 0);
			m1.Get_m(0, 0) = m2.Get_m(1, 1) = 2.0;
			m1.Get_m(1, 0) = m2.Get_m(0, 0) = 7.0;
			m1.Get_m(0, 1) = m2.Get_m(1, 0) = 3.0;
			m1.Get_m(1, 1) = m2.Get_m(0, 1) = 4.0;
			m2 = m1 * m2;
			Assert::AreEqual(m2.Get_m(0, 0),42.0);
			Assert::AreEqual(m2.Get_m(1, 0), 20.0);
			Assert::AreEqual(m2.Get_m(0, 1), 37.0);
			Assert::AreEqual(m2.Get_m(1, 1), 17.0);
		}
	};
}
