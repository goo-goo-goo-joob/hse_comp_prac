#pragma once
#include "ADT.h"
#include <vector>
#pragma warning(disable: 4996)

class Date : public ADT {
	unsigned int day;
	unsigned int month;
	unsigned int year;
	static bool toDerived(const ADT* obj, Date ** target = nullptr)
	{
		if (obj->GetKind() != ItemKind::ITEM_DATE) {
			return false;
		}
		if (target)
			*target = (Date*)obj;
		return true;
	}
	virtual void print(ostream & out) const override
	{
		out << "Date: " << this->year << "." << this->month << "." << this->day;
	}

	virtual void scan(istream & in) override
	{
		vector<string> strings;
		string input;
		getline(in, input);
		istringstream f(input);
		string s;
		while (getline(f, s, '.')) {
			strings.push_back(s);
		}
		if (strings[0][0] == '0')
			day = strings[0][1] - '0';
		else
			day = stoi(strings[0]);
		if (strings[1][0] == '0')
			month = strings[1][1] - '0';
		else
			month = stoi(strings[1]);
		year = stoi(strings[2]);
	}
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(const Date &dt): day(dt.day), month(dt.month), year(dt.year) {}
	Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y) {
		month = (month % 13 + 13) % 13;
		if (month == 2 && (y % 4 != 0 || y % 100 == 0 && y % 400 != 0)) {
			day = (day % 29 + 29) % 29;
		}
		else if (month == 2) {
			day = (day % 30 + 30) % 30;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			day = (day % 31 + 31) % 31;
		}
		else {
			day = (day % 32 + 32) % 32;
		}
	}
	Date operator=(const Date &rD) {
		day = rD.day;
		month = rD.month;
	Date operator=(const ADT* rD) {
		Date* obj;
		if (!toDerived(rD, &obj)) {
			throw exception("wrong type");
		}
		day = obj->day;
		month = obj->month;
		year = obj->year;
		return *this;
	}
	~Date() {}
	bool operator==(const ADT &rD) const override {
		Date* obj;
		if (!toDerived(&rD, &obj)) {
			return false;
		}
		return day == obj->day && month == obj->month && year == obj->year;
	}
	bool operator!=(const ADT &rD) const override {
		Date* obj;
		if (!toDerived(&rD, &obj)) {
			return false;
		}
		return !(*this == rD);
	}
	bool operator<(const ADT &rD) const override {
		Date* obj;
		if (!toDerived(&rD, &obj)) {
			return false;
		}
		if (year > obj->year)
			return false;
		if (month > obj->month)
			return false;
		if (day >= obj->day)
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
};

istream & operator >> (istream & in, Date & dt)
{
	dt.scan(in);
	return in;
}

ostream & operator << (ostream & out, const Date & d)
{
	d.print(out);
	return out;
}