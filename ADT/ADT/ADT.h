// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "ADT_types.h"
using namespace std;

class ADT {
public:
	ADT() {};
	//virtual ADT operator=(const ADT &rADT);
	virtual ~ADT() {};
	virtual bool operator==(const ADT &rBi) const = 0;
	virtual bool operator<(const ADT &rADT) const = 0;
	virtual bool operator<=(const ADT &rADT) const = 0;
	virtual bool operator>(const ADT &rADT) const = 0;
	virtual bool operator>=(const ADT &rADT) const = 0;
	virtual ItemKind GetKind() const = 0;
	virtual void print(ostream& out) const = 0;
	friend ostream & operator<< (ostream &out, const ADT &adt)
	{
		adt.print(out);
		return out;
	}
	//friend istream & operator>> (istream &in, ADT &adt);
};

class Date : public ADT {
	size_t day;
	size_t month;
	size_t year;
	static bool toDerived(const ADT* obj, Date * target = nullptr)
	{
		if (obj->GetKind() != ItemKind::ITEM_DATE) {
			return false;
		}
		if (target)
			target = (Date*)obj;
		return true;
	}
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(size_t d, size_t m, size_t y) : day(d), month(m), year(y) {}
	Date operator=(const Date &rD) {
		day = rD.day;
		month = rD.month;
		year = rD.year;
		return *this;
	}
	~Date() {}
	bool operator==(const ADT &rD) const override {
		Date obj;
		if (!toDerived(&rD, &obj)) {
			return false;
		}
		return day == obj.day && month == obj.month && year == obj.year;
	}
	bool operator<(const ADT &rD) const override {
		Date obj;
		if (!toDerived(&rD, &obj)) {
			return false;
		}
		if (year > obj.year)
			return false;
		if (month > obj.month)
			return false;
		if (day >= obj.day)
			return false;
		else
			return true;
	}
	bool operator>(const ADT &rD) const override {
		if (!toDerived(&rD)) {
			return false;
		}
		return !(*this < rD || *this == rD);
	}
	bool operator>=(const ADT &rD) const override {
		if (!toDerived(&rD)) {
			return false;
		}
		return !(*this < rD);
	}
	bool operator<=(const ADT &rD) const override {
		if (!toDerived(&rD)) {
			return false;
		}
		return *this < rD || *this == rD;
	}
	friend ostream & operator<< (ostream &out, const Date &d);
	friend istream & operator>> (istream &in, Date &d);

	virtual ItemKind GetKind() const override
	{
		return ItemKind::ITEM_DATE;
	}

	virtual void print(ostream & out) const override
	{
		out << "Date: " << this->year << "." << this->month << "." << this->day << endl;
	}

};

istream & operator >> (istream & in, Date & dt)
{
	string s;
	getline(in, s);
	size_t d = stoi(s);
	getline(in, s);
	size_t m = stoi(s);
	getline(in, s);
	size_t y = stoi(s);
	Date tmp(d, m, y);
	dt = tmp;
	return in;
}

ostream & operator << (ostream & out, const Date & d)
{
	d.print(out);
	return out;
}