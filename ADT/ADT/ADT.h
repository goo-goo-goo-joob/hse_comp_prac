// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class ADT {
public:
	ADT();
	virtual ADT operator=(const ADT &rADT);
	virtual ~ADT();
	virtual bool isZero() const;
	virtual bool operator==(const ADT &rBi) const;
	virtual bool operator<(const ADT &rADT) const;
	virtual bool operator<=(const ADT &rADT) const;
	virtual bool operator>(const ADT &rADT) const;
	virtual bool operator>=(const ADT &rADT) const;
	friend ostream & operator<< (ostream &out, const ADT &adt);
	friend istream & operator>> (istream &in, ADT &adt);
};

class Data : public ADT {
	size_t day;
	size_t month;
	size_t year;
public:
	Data() {
		day = 0;
		month = 0;
		year = 0;
	}
	Data(size_t d, size_t m, size_t y) : day(d), month(m), year(y) {}
	Data operator=(const Data &rD) {
		day = rD.day;
		month = rD.month;
		year = rD.year;
		return *this;
	}
	~Data() {}
	bool operator==(const Data &rD) const {
		return day == rD.day && month == rD.month && year == rD.year;
	}
	bool operator<(const Data &rADT) const {
		if (year > rADT.year)
			return false;
		if (month > rADT.month)
			return false;
		if (day >= rADT.day)
			return false;
		else
			return true;
	}
	bool operator>(const Data &rD) const {
		return (*this < rD || *this == rD) ? false : true;
	}
	bool operator>=(const Data &rD) const {
		return (*this < rD) ? false : true;
	}
	bool operator<=(const Data &rD) const {
		return (*this < rD || *this == rD) ? true : false;
	}
	friend ostream & operator<< (ostream &out, const Data &d);
	friend istream & operator>> (istream &in, Data &d);
};

istream & operator >> (istream & in, Data & dt)
{
	string s;
	getline(in, s);
	size_t d = stoi(s);
	getline(in, s);
	size_t m = stoi(s);
	getline(in, s);
	size_t y = stoi(s);
	Data tmp(d, m, y);
	dt = tmp;
	return in;
}

ostream & operator << (ostream & out, const Data & d)
{
	out << d.day << "." << d.month << "." << d.year << endl;
	return out;
}