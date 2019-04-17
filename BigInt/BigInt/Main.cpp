// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "BigInt.h"

int main() {
	BigInt bi1("123");
	BigInt bi2(bi1);
	BigInt bi3("-129934811447123020117172145698449");
	BigInt bi4("");
	cout << bi1 << bi2 << bi4 << (bi1 - bi3);
	try {
		BigInt b1;
		cin >> b1;
		cout << b1;
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl;
	}
	cout << string(bi1) << " " << bi1[0] << " " << bi1[1] << " " << bi1[2] << " " << bi1[3] << endl;
	try {
		BigInt a("-10000");
		BigInt b("0");
		cout << a / b;
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl;
	}
	bi1(-1, '9');
	cout << string(bi1) << " " << bi1[0] << " " << bi1[1] << " " << bi1[2] << " " << bi1[3] << endl;
	cout << (-bi1 * bi2) << (bi1 / bi2);
	return 0;
}