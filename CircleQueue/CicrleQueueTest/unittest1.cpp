// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CircleQueue/CircleQueue.h"
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
			CircleQueue<int> q(cap);
			int thrown = 0;
			for (int i = 0; i < cap + extra_read; i++) {
				try {
					q.pushBack(0);
				}
				catch (const exception& e) {
					thrown++;
				}
			}
			Assert::AreEqual(thrown, extra_read);
		}
		TEST_METHOD(TestMethodInsert)
		{
			const int cap = 10;
			const int extra_read = 5;
			CircleQueue<int> q(cap);
			int thrown = 0;
			for (int i = 0; i < cap + extra_read; i++) {
				try {
					q.insert(111, 0);
				}
				catch (const exception& e) {
					thrown++;
				}
			}
			Assert::AreEqual(thrown, extra_read);
		}
		TEST_METHOD(TestMethodReadForward)
		{
			const int cap = 10;
			CircleQueue<int> q(cap);
			for (int i = 0; i < cap; i++) {
					q.pushBack(i);
			}
			for (int i = 0; i < cap; i++) {
				Assert::AreEqual(q.pop(0), i);
			}
		}
		TEST_METHOD(TestMethodReadBackword)
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
	};
}