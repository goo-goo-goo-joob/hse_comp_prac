// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "Date.h"

int main() {
	Date d1(1, 8, 1999);
	Date d2;
	cin >> d2;
	cout << (d1 <= d2);
	return 0;
}