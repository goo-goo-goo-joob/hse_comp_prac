// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "BigInt.h"

int main() {
	try {
		BigInt bi1("-1267650600228229401496703205376");
		BigInt bi2(bi1);
		BigInt bi3("-129934811447123020117172145698449");
		BigInt bi4("");
		cout << bi1 << bi2 << bi4 << (bi1 - bi3);
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl;
	}
	BigInt b1("340282366920938463463374607431768211456");
	BigInt b2("147808829414345923316083210206383297601");
	BigInt b3("192473537506592540147291397225384913855");
	cout << (b1 - b2 == b3);
	return 0;
}