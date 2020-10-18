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
			m1.Get_m(0, 0) = 3;
			m1.Get_m(1, 0) = 2;
			m1.Get_m(0, 1) = 4;
			m2 = m1.transposition();
			Assert::AreEqual(m2.Get_m(0, 1), 2);
			Assert::AreEqual(m2.Get_m(1, 0), 4);
			
		}
	};
}
