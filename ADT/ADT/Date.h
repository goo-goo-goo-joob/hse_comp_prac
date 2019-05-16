#pragma once
#include "ADT.h"

class Date : public ADT {
	size_t day;
	size_t month;
	size_t year;
	static bool toDerived(const ADT* obj, Date ** target = nullptr)
	{
		if (obj->GetKind() != ItemKind::ITEM_DATE) {
			return false;
		}
		if (target)
			*target = (Date*)obj;
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

	virtual void print(ostream & out) const override
	{
		out << "Date: " << this->year << "." << this->month << "." << this->day << endl;
	}

	virtual void scan(istream & in) override
	{
		string s;
		getline(in, s);
		day = stoi(s);
		getline(in, s);
		month = stoi(s);
		getline(in, s);
		year = stoi(s);
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