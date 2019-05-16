// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "ADT.h"

int main() {
	Data d(3, 8, 1999);
	cout << d;
	Data d1;
	cin >> d1;
	cout << (d > d1);
	return 0;
}