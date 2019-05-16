#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADTTest
{		
	TEST_CLASS(UnitTestDate)
	{
	public:
		
		TEST_METHOD(TestNotEqual)
		{
			Date d1(1, 8, 1999);
			Date d2(3, 8, 1999);
			Assert::IsTrue(d1 < d2);
			Assert::IsTrue(d1 <= d2);
			Assert::IsTrue(d2 > d1);
			Assert::IsTrue(d2 >= d1);
			Assert::IsTrue(d1 != d2);
			Assert::IsTrue(d2 != d1);

			Assert::IsFalse(d1 > d2);
			Assert::IsFalse(d1 >= d2);
			Assert::IsFalse(d2 < d1);
			Assert::IsFalse(d2 <= d1);
			Assert::IsFalse(d2 == d1);
			Assert::IsFalse(d1 == d2);

		}

	};
}