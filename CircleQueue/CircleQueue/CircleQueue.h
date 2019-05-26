// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once
#include <iostream>
#include "../../ADT/ADT/ADT.h"
#include "../../ADT/ADT/Date.h"
#include "../../BigInt/BigInt/BigInt.h"
using namespace std;

//template <typename T>
class CircleQueue {
	size_t size;
	size_t cap;
	ADT** values;
	size_t head;
	size_t tail;
	bool sorted;
	size_t toIndex(size_t i) {
		return (i + tail) % cap;
	}
	void deleteAt(size_t i) {
		delete values[i];
		values[i] = nullptr;
		size--;
	}
	void incHead() {
		head = (head + 1) % cap;
	}
	void incTail() {
		tail = (tail + 1) % cap;
	}
public:
	CircleQueue(size_t capacity) {
		values = new ADT*[capacity];
		for (size_t i = 0; i < capacity; i++) {
			values[i] = nullptr;
		}
		head = 0;
		size = 0;
		tail = 0;
		cap = capacity;
		sorted = false;
	}
	~CircleQueue() {
		for (size_t i = 0; i < cap; i++) {
			delete values[i];
		}
		delete[] values;
	}
	void pushBack(ADT* elm) {
		if (size < cap) {
			//ADT* tmp = new ADT;
			//*tmp = elm;
			ADT* tmp = elm->CoPy();
			values[head] = tmp;
			incHead();
			size++;
			sorted = false;
		}
		else
			throw exception("queue is full");
	}
	void insert(ADT* elm, size_t pos) {
		if (size >= cap)
			throw exception("queue is full");
		if (pos > size)
			throw exception("position out of range");
		ADT* tmp = elm->CoPy();
		for (size_t i = size; i > pos; i--) {
			values[toIndex(i)] = values[toIndex(i - 1)];
		}
		values[pos] = tmp;
		incHead();
		size++;
		sorted = false;
	}
	ADT* pop(size_t pos) {
		if (pos < size) {
			ADT* tmp = values[toIndex(pos)];
			for (size_t i = pos; i < size - 1; i++) {
				values[toIndex(i)] = values[toIndex(i + 1)];
			}
			values[toIndex(size - 1)] = tmp;
			ADT* result = tmp->CoPy();
			deleteAt(toIndex(size - 1));
			//delete &tmp;
			return result;
		}
		throw exception("index out of range exception");
	}
	void sort() {
		for (size_t i = 0; i < size - 1; i++)
			for (size_t j = 0; j < size - i - 1; j++)
				if (*values[j] > *values[j + 1])
				{
					ADT* tmp = values[j];
					values[j] = values[j + 1];
					values[j + 1] = tmp;
				}
		sorted = true;
	}
	friend ostream & operator<< (ostream &out, const CircleQueue &cq) {
		for (size_t i = 0; i < cq.size; i++)
			out << *cq.values[i] << " ";
		out << endl;
		return out;
	}
	friend istream & operator>> (istream &in, CircleQueue &cq) {
		{
			while (cq.cap != cq.size && !in.eof() && !in.fail())
			{
				ADT *tmp = nullptr;
				in >> *tmp;
				if (!in.eof() && !in.fail()) {
					cq.pushBack(tmp);
				}
			}
			return in;
		}
	}
	void PushSort(ADT* elm) {
		if (size >= cap)
			throw exception("queue is full");
		if (!sorted) {
			pushBack(elm);
			sort();
		}
		else {
			size_t i = 0;
			while (*elm < *values[i])
				i++;
			insert(elm, i);
			sorted = true;
		}
	}
};

