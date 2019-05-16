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
	virtual bool operator!=(const ADT &rBi) const = 0;
	virtual bool operator<(const ADT &rADT) const = 0;
	virtual bool operator<=(const ADT &rADT) const = 0;
	virtual bool operator>(const ADT &rADT) const = 0;
	virtual bool operator>=(const ADT &rADT) const = 0;
	virtual ItemKind GetKind() const = 0;
	virtual void print(ostream& out) const = 0;
	virtual void scan(istream& in) = 0;
	friend ostream & operator<< (ostream &out, const ADT &adt)
	{
		adt.print(out);
		return out;
	}
	friend istream & operator>> (istream &in, ADT &adt) {
		adt.scan(in);
		return in;
	}
};