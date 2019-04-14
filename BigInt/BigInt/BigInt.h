// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once
//#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int base = 10;

class BigInt {
	char* value;//дес€ична€ система счислени€ дл€ записи каждого символа-цифры
	size_t size;
	bool sign;//pos - true, neg - false
public:
	BigInt(string s) {
		int i;
		if (s[0] != '-') {
			sign = true;
			size = s.length();
			i = s.length() - 1;
		}
		else {
			sign = false;
			size = s.length() - 1;
			i = s.length() - 1;
		}
		value = new char[size];
		int j = 0;
		while (j < size) {
			if (!isdigit(s[i])) {
				throw invalid_argument("received not digit");
			}
			else
				value[j++] = s[i--];
		}
	}
	BigInt(const BigInt &newInt) {
		char* newVal = newInt.getValue();
		sign = newInt.getSign();
		size = newInt.getSize();
		value = new char[size];
		memcpy(value, newVal, size * sizeof(char));
	}
	~BigInt() {
		delete[] value;
	}
	char* getValue() const {
		return value;
	}
	unsigned int getSize() const {
		return size;
	}
	bool getSign() const {
		return sign;
	}
	void setSign(bool b) {
		sign = b;
	}
	BigInt operator=(const BigInt &rBi) {
		size = rBi.size;
		sign = rBi.sign;
		char* stmp = rBi.value;
		delete[] value;
		value = new char[size];
		int i = 0;
		while (i < size) {
			if (!isdigit(stmp[i])) {
				throw invalid_argument("received not digit");
			}
			else
				value[i] = stmp[i];
			i++;
		}
		return *this;
	}

	bool operator<(const BigInt &rBi) const {
		bool rSign = rBi.sign;
		if (sign != rSign)
			return sign == true ? true : false;
		unsigned int rSize = rBi.size;
		if (size != rSize)
			return size < rSize;
		char* valBi = rBi.value;
		int i = size - 1;
		while (i >= 0) {
			if (value[i] > valBi[i])
				return false;
			else if (value[i] < valBi[i])
				return true;
			i--;
		}
		return true;
	}
	bool operator==(const BigInt &rBi) const {
		bool result = sign == rBi.sign && size == rBi.size;
		for (int i = 0; i < size && result; i++) {
			result = value[i] == rBi.value[i];
		}
		return result;
	}
	BigInt operator-() {
		sign = !(sign);
		return *this;
	}
	BigInt operator-(const BigInt &rBi) const {
		bool rSign = rBi.sign;
		if (sign && rSign) {
			if (*this < rBi) {
				BigInt tmp = rBi - *this;
				tmp.setSign(false);
				return tmp;
			}
			char* valBi = rBi.value;
			unsigned int rSize = rBi.size;
			string tmp = "";
			int rem = 0;
			for (int i = 0; i < max(size, rSize); i++) {
				if (i >= rSize) {
					tmp.push_back(((value[i] - 48) + rem + 20) % 10 + 48);
					if ((value[i] - 48) + rem < 0)
						rem = - 1;
					else {
						rem = 0;
					}
				}
				else {
					char a = valBi[i];
					char b = value[i];
					tmp.push_back((-(valBi[i] - 48) + (value[i] - 48) + rem + 20) % 10 + 48);
					if (-(valBi[i] - 48) + (value[i] - 48) + rem < 0)
						rem = - 1;
					else {
						rem = 0;
					}
				}
			}
			if (rem) {
				tmp.push_back(abs(rem) + 48);
			}
			int i = 0;
			while (tmp[i] == '0') {
				tmp.pop_back();
				i++;
			}
			reverse(tmp.begin(), tmp.end());
			return BigInt(tmp);
		}
		else if (!sign && rSign) {
			BigInt tmp1(*this);
			tmp1.setSign(true);
			BigInt tmp = tmp1 + rBi;
			tmp.setSign(false);
			return tmp;
		}
		else if (sign && !rSign) {
			BigInt tmp(rBi);
			tmp.setSign(true);
			return *this + tmp;
		}
		else {
			BigInt tmp(rBi);
			BigInt tmp1(*this);
			tmp.setSign(true);
			tmp1.setSign(true);
			return tmp - tmp1;
		}

	}
	BigInt operator+(const BigInt &rBi) const {
		char* valBi = rBi.value;
		bool rSign = rBi.sign;
		unsigned int rSize = rBi.size;
		string tmp = "";
		if (sign == rSign) {
			unsigned int rem = 0;
			for (int i = 0; i < max(size, rSize); i++) {
				if (i >= size) {
					tmp.push_back(((valBi[i] - 48) + rem) % 10 + 48);
					rem = ((valBi[i] - 48) + rem) / 10;
				}
				else if (i >= rSize) {
					tmp.push_back(((value[i] - 48) + rem) % 10 + 48);
					rem = ((value[i] - 48) + rem) / 10;
				}
				else {
					tmp.push_back(((valBi[i] - 48) + (value[i] - 48) + rem) % 10 + 48);
					rem = ((valBi[i] - 48) + (value[i] - 48) + rem) / 10;
				}
			}
			if (rem) {
				tmp.push_back(rem);
			}
			if (!sign) {
				tmp.push_back('-');
			}
			reverse(tmp.begin(), tmp.end());
			return BigInt(tmp);
		}
		else if (!sign) {
			BigInt tmp(*this);
			tmp.setSign(true);
			return rBi - tmp;
		}
		else {
			BigInt tmp(rBi);
			tmp.setSign(true);
			return *this - tmp;
		}
	}
	void operator+=(const BigInt&rBi) {
		BigInt tmp = *this + rBi;
		*this = tmp;
	}
	void operator-=(const BigInt&rBi) {
		BigInt tmp = *this - rBi;
		*this = tmp;
	}
	friend ostream & operator<< (ostream &out, const BigInt &bi);
};

ostream & operator << (ostream &out, const BigInt &bi)
{
	char* val = bi.getValue();
	if (!bi.getSign()) {
		out << "-";
	}
	for (int i = bi.getSize() - 1; i >= 0; i--)
		out << val[i];
	out << endl;
	return out;
}