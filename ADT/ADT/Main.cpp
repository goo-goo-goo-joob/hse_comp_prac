// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "ADT.h"

int main() {
	Date d(3, 8, 1999);
	cout << d;
	Date d1(3, 8, 2000);
	//cin >> d1;
	cout << (d > d1);
	cout << (d < d1);
	return 0;
}