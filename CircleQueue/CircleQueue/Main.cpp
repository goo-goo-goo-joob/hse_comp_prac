// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "CircleQueue.h"
#include "iostream"

int main() {
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
	return 0;
}