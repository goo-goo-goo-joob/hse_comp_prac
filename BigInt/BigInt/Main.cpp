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
	BigInt b1("1606938044258990275541962092341162602522202993782792835301376");
	BigInt b2("-265613988875874769338781322035779626829233452653394495974574961739092490901302182994384699044001");
	BigInt b3("-265613988875874769338781322035779625222295408394404220432612869397929888379099189211591863742625");
	b2 += b1;
	cout << (b2 == b3);
	cout << -b2;
	return 0;
}