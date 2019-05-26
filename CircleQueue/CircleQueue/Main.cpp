// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#include "CircleQueue.h"
#include "../../ADT/ADT/Date.h"
#include "../../BigInt/BigInt/BigInt.h"
#include "iostream"

int main() {
	//const int cap = 10;
	//CircleQueue q(cap + 1);
	//Date d1(3, 8, 1999);
	//Date d2;
	//cin >> d2;
	//BigInt b1("-123456789");
	//q.pushBack(&d1);
	////cin >> q;
	//try {
	//	q.PushSort(&b1);
	//}
	//catch (const exception& e) {
	//	cerr << e.what() << endl;
	//}
	//cout << q;
	//ADT* d1;
	//{
	//	Date dt(19, 9, 1958);
	//	d1 = dt.CoPy();
	//}

	//ADT* d2 = d1->CoPy();
	//delete d1;
	for (int it = 0; it < 1000; it++)
	{
		const int cap = 10;
		const int extra_read = 5;
		CircleQueue q(cap);
		int thrown = 0;
		Date dt(19, 9, 1958);
		for (int i = 0; i < cap + extra_read; i++) {
			try {
				q.insert(&dt, 0);
			}
			catch (const exception&) {
				thrown++;
			}
		}

	}
	return 0;
}