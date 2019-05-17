// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CircleQueue/CircleQueue.h"
#include "../CircleQueue/CircleQueue.h"
#include "../../BigInt/BigInt/BigInt.h"
#include "../../ADT/ADT/ADT.h"
#include "../../ADT/ADT/Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CicrleQueueTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodPushBack)
		{
			const int cap = 10;
			const int extra_read = 5;
			CircleQueue q(cap);
			int thrown = 0;
			BigInt bi("123832892108");
			for (int i = 0; i < cap + extra_read; i++) {
				try {
					q.pushBack(&bi);
				}
				catch (const exception&) {
					thrown++;
				}
			}
			Assert::AreEqual(thrown, extra_read);
		}
		TEST_METHOD(TestMethodInsert)
		{
			const int cap = 10;
			const int extra_read = 5;
			CircleQueue q(cap);
			int thrown = 0;
			Date dt(19, 9, 1958);
			for (int i = 0; i < cap + extra_read; i++) {
				try {
					q.insert(&dt, 0);
				}
				catch (const exception&) {
					thrown++;
				}
			}
			Assert::AreEqual(thrown, extra_read);
		}
		TEST_METHOD(TestMethodReadForward)
		{
			const int cap = 10;
			CircleQueue q(cap);
			for (int i = 0; i < cap; i++) {
					q.pushBack(&BigInt((char*)(i)));
			}
			for (int i = 0; i < cap; i++) {
				Assert::AreEqual((BigInt*)q.pop(0), &BigInt((char*)(i)));
			}
		}
		/*TEST_METHOD(TestMethodReadBackword)
		{
			const int cap = 10;
			CircleQueue<int> q(cap);
			for (int i = 0; i < cap; i++) {
				q.pushBack(i);
			}
			for (int i = cap - 1; i >= 0; i--) {
				Assert::AreEqual(q.pop(i), i);
			}
		}
		TEST_METHOD(TestMethodSort)
		{
			const int cap = 10;
			CircleQueue<int> q(cap);
			for (int i = 0; i < cap; i++) {
				q.pushBack(rand());
			}
			q.sort();
			int el = q.pop(0);
			for (int i = 0; i < cap - 1; i++) {
				int n = q.pop(0);
				Assert::IsTrue(n > el);
				el = n;
			}
		}*/
	};
}