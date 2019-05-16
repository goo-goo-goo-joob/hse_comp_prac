// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "CircleQueue.h"
#include "iostream"

int main() {
	const int cap = 10;
	CircleQueue<int> q(cap + 1);
	q.pushBack(42);
	cin >> q;
	try {
		q.PushSort(11);
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	cout << q;
	return 0;
}