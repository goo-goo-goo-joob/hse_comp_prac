// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "BigInt.h"

int main() {
	try {
		BigInt bi1("-123456789");
		BigInt bi2(bi1);
		BigInt bi3("-877678912258218746");
		BigInt bi4("");
		cout << bi1 << bi2 << bi4 << (bi1 - bi3);
	}
	catch (const invalid_argument& e) {
		cerr << e.what() << endl;
	}
	return 0;
}