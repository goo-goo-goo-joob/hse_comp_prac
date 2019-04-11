// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once
#include <cstring>
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
	unsigned int getSize() const {//может ли быть настолько длинным, чтобы не хватило места под размер?
		return size;
	}
	bool getSign() const {
		return sign;
	}
	void setSign(bool b) {
		sign = b;
	}
	bool operator<(const BigInt &rBi) const {
		bool rSign = rBi.getSign();
		if (sign != rSign)
			return sign == true ? true : false;
		unsigned int rSize = rBi.getSize();
		if (size != rSize)
			return size < rSize;
		char* valBi = rBi.getValue();
		int i = size - 1;
		while (i >= 0) {
			if (value[i] > valBi[i])
				return false;
			i--;
		}
		return true;
	}

	BigInt operator-(const BigInt &rBi) const {
		bool rSign = rBi.getSign();
		if (sign && rSign) {
			if (*this < rBi) {
				BigInt tmp = rBi - *this;
				tmp.setSign(false);
				return tmp;
			}
			char* valBi = rBi.getValue();
			unsigned int rSize = rBi.getSize();
			string tmp = "";
			int rem = 0;
			for (int i = 0; i < max(size, rSize); i++) {
				if (i >= size) {
					tmp.push_back((-(valBi[i] - 48) + rem + 20) % 10 + 48);
					if (-(valBi[i] - 48) + rem < 0)
						rem = (-(valBi[i] - 48) + rem) / 10 - 1;
					else {
						rem = 0;
					}
				}
				else {
					tmp.push_back((-(valBi[i] - 48) + (value[i] - 48) + rem + 20) % 10 + 48);
					if(-(valBi[i] - 48) + (value[i] - 48) + rem < 0)
						rem = (-(valBi[i] - 48) + (value[i] - 48) + rem)/10 - 1;
					else {
						rem = 0;
					}
				}
			}
			if (rem) {
				tmp.push_back(abs(rem) + 48);
			}
			int i = 0;
			while (tmp[i] != '0') {
				tmp.pop_back();
				i++;
			}
			reverse(tmp.begin(), tmp.end());
			return BigInt(tmp);
		}
		else if (!sign && rSign) {
			BigInt tmp = *this + rBi;
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
			tmp.setSign(true);
			return tmp - *this;
		}
		
	}
	BigInt operator+(const BigInt &rBi) const {
		char* valBi = rBi.getValue();
		bool rSign = rBi.getSign();
		unsigned int rSize = rBi.getSize();
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
			return rBi - *this;
		}
		else {
			return *this - rBi;
		}
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