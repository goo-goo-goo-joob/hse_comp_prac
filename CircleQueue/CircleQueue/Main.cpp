// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "CircleQueue.h"
#include "iostream"

int main() {
	const int cap = 10;
	CircleQueue<int> q(cap + 1);
	q.pushBack(42);
	for (int i = 0; i < cap; i++) {
		q.insert(i, 0);
	}
	//q.pop(0);
	//q.insert(112, 1);
	cout << q;
	return 0;
}