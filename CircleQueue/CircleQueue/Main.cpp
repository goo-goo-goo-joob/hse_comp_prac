// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "CircleQueue.h"
#include "iostream"

int main() {
	CircleQueue<int> q(10);
	for (int i = 0; i < 10; i++) {
		q.pushBack(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << q.pop(0) << endl;
	}

	return 0;
}