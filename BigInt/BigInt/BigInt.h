// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include "../../ADT/ADT/ADT.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

const int base = 10;

class BigInt: public ADT {
	char* value;//дес€ична€ система счислени€ дл€ записи каждого символа-цифры
	size_t size;
	bool sign;//pos - true, neg - false
	static bool toDerived(const ADT* obj, BigInt ** target = nullptr)
	{
		if (obj->GetKind() != ItemKind::ITEM_BIGINT) {
			return false;
		}
		if (target)
			*target = (BigInt*)obj;
		return true;
	}
public:
	BigInt() {
		value = nullptr;
		size = 0;
		sign = true;
	}
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
		value = new char[size + 1];
		value[size] = 0;
		for (int i = 0; i < size; i++) {
			value[i] = 0;
		}
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
		value = new char[size + 1];
		value[size] = 0;
		for (int i = 0; i < size; i++) {
			value[i] = 0;
		}
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
		value = new char[size + 1];
		value[size] = 0;
		for (int i = 0; i < size; i++) {
			value[i] = 0;
		}
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

	bool operator<(const ADT &rBi) const override {
		BigInt* obj;
		if (!toDerived(&rBi, &obj)) {
			return false;
		}
		bool rSign = obj->sign;
		if (sign != rSign)
			return sign == true ? true : false;
		unsigned int rSize = obj->size;
		if (size != rSize)
			return size < rSize;
		char* valBi = obj->value;
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
	bool operator>(const ADT &rBi) const override {
		if (!toDerived(&rBi)) {
			return false;
		}
		return !(*this < rBi || *this == rBi);
	}
	bool operator>=(const ADT &rBi) const override {
		if (!toDerived(&rBi)) {
			return false;
		}
		return !(*this < rBi);
	}
	bool operator<=(const ADT &rBi) const override {
		if (!toDerived(&rBi)) {
			return false;
		}
		return *this < rBi || *this == rBi;
	}
	bool isZero() const {
		return size == 1 && value[0] == '0';
	}
	bool operator==(const ADT &rBi) const override {
		BigInt* obj;
		if (!toDerived(&rBi, &obj)) {
			return false;
		}
		if (isZero() && obj->isZero())
			return true;
		bool result = sign == obj->sign && size == obj->size;
		for (int i = 0; i < size && result; i++) {
			result = value[i] == obj->value[i];
		}
		return result;
	}
	bool operator!=(const ADT &rD) const override {
		BigInt* obj;
		if (!toDerived(&rD, &obj)) {
			return false;
		}
		return !(*this == rD);
	}
	BigInt operator-() {
		sign = !(sign);
		return *this;
	}
	BigInt operator-(const BigInt &rBi) const {
		bool rSign = rBi.sign;
		if (*this == rBi)
			return BigInt("0");
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
						rem = -1;
					else {
						rem = 0;
					}
				}
				else {
					char a = valBi[i];
					char b = value[i];
					tmp.push_back((-(valBi[i] - 48) + (value[i] - 48) + rem + 20) % 10 + 48);
					if (-(valBi[i] - 48) + (value[i] - 48) + rem < 0)
						rem = -1;
					else {
						rem = 0;
					}
				}
			}
			if (rem) {
				tmp.push_back(abs(rem) + 48);
			}
			int i = size - 1;
			while (tmp[i] == '0') {
				tmp.pop_back();
				i--;
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
		*this = *this + rBi;
	}
	void operator-=(const BigInt&rBi) {
		*this = *this - rBi;
	}
	operator string() const {
		string str = ((string)value).substr(0, size);
		if (!sign)
			str.push_back('-');
		reverse(str.begin(), str.end());
		return str;
	}
	char operator[](int i) const {
		i = (i % size + size) % size;
		return value[i];
	}
	void operator()(int pos, char val) {
		pos = (pos % size + size) % size;
		if (!isdigit(val))
			throw invalid_argument("received not digit");
		else
			value[pos] = val;
	}
	BigInt operator*(const BigInt &rBi) const {
		if (this->isZero() || rBi.isZero())
			return BigInt("0");
		size_t len = size + rBi.size + 1;
		vector<int> tmp(len, 0);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < rBi.size; j++)
				tmp[i + j] += (value[i] - '0') * (rBi.value[j] - '0');
		for (int i = 0; i < len - 1; i++)
		{
			tmp[i + 1] += tmp[i] / 10;
			tmp[i] %= 10;
		}
		while (!tmp[--len])
			tmp.pop_back();
		ostringstream oss;
		if (!tmp.empty())
		{
			copy(tmp.begin(), tmp.end(),
				std::ostream_iterator<int>(oss));
		}
		string str = oss.str();
		if (sign != rBi.sign)
			str.push_back('-');
		reverse(str.begin(), str.end());
		return BigInt(str);
	}
	BigInt Abs() const {
		BigInt tmp(*this);
		tmp.sign = true;
		return tmp;
	}
	BigInt operator/ (const BigInt &rBi) const {
		if (rBi.isZero())
			throw invalid_argument("alarm! division by zero");
		else {
			if (this->Abs() < rBi.Abs())
				return BigInt("0");
			string sup = ((string)*this).substr(int(!sign), rBi.size);
			BigInt tmp(sup);
			string val("");
			if (sign != rBi.sign)
				val.push_back('-');
			for (int i = size - rBi.size; i >= 0; i--) {
				int j = 0;
				while (rBi.Abs() <= tmp.Abs()) {
					tmp -= rBi.Abs();
					j++;
				}
				if (j != 0 || i != size - rBi.size)
					val.push_back(char(j) + '0');
				if (i) {
					string str("");
					if (tmp.isZero())
						str = value[i - 1];
					else {
						str = (string)tmp;
						str.push_back(value[i - 1]);
					}
					BigInt tmp1(str);
					tmp = tmp1;
				}
			}
			return BigInt(val);
		}
	}
	void operator*=(const BigInt&rBi) {
		*this = *this * rBi;
	}
	void operator/=(const BigInt&rBi) {
		*this = *this / rBi;
	}
	friend ostream & operator<< (ostream &out, const BigInt &bi);
	friend istream & operator>> (istream &in, BigInt &bi);

	virtual ItemKind GetKind() const override
	{
		return ItemKind::ITEM_BIGINT;
	}

	virtual void print(ostream & out) const override
	{
		if (!sign) {
			out << "-";
		}
		for (int i = size - 1; i >= 0; i--)
			out << value[i];
		out << endl;
	}

	virtual void scan(istream & in) override
	{
		string s;
		getline(in, s);
		BigInt tmp(s);
		*this = tmp;
	}
};

istream& operator >> (istream& in, BigInt & bi)
{
	bi.scan(in);
	return in;
}

ostream & operator << (ostream &out, const BigInt &bi)
{
	bi.print(out);
	return out;
}