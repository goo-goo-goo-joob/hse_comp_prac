// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class CircleQueue {
	size_t size;
	size_t cap;
	T** values;
	size_t head;
	size_t tail;
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
		values = new T*[capacity];
		for (size_t i = 0; i < capacity; i++) {
			values[i] = nullptr;
		}
		head = 0;
		size = 0;
		tail = 0;
		cap = capacity;
	}
	~CircleQueue() {
		for (size_t i = 0; i < cap; i++) {
			delete values[i];
		}
		delete[] values;
	}
	void pushBack(T elm) {
		if (size < cap) {
			T* tmp = new T;
			*tmp = elm;
			values[head] = tmp;
			incHead();
			size++;
		}
		else
			throw exception("queue is full");
	}
	void insert(T elm, size_t pos) {
		if (size >= cap)
			throw exception("queue is full");
		if (pos > size)
			throw exception("position out of range");
		T* tmp = new T;
		*tmp = elm;
		for (size_t i = size; i > pos; i--) {
			values[toIndex(i)] = values[toIndex(i - 1)];
		}
		values[pos] = tmp;
		incHead();
		size++;
	}
	T pop(size_t pos) {
		if (pos < size) {
			T* tmp = values[toIndex(pos)];
			for (size_t i = pos; i < size - 1; i++) {
				values[toIndex(i)] = values[toIndex(i + 1)];
			}
			values[toIndex(size - 1)] = tmp;
			T result = *tmp;
			deleteAt(toIndex(size - 1));
			return result;
		}
		throw exception("index out of range exception");
	}
	void sort() {
		for (size_t i = 0; i < size - 1; i++)
			for (size_t j = 0; j < size - i - 1; j++)
				if (*values[j] > *values[j + 1])
				{
					T* tmp = values[j];
					values[j] = values[j + 1];
					values[j + 1] = tmp;
				}
	}
	friend ostream & operator<< (ostream &out, const CircleQueue<T> &cq) {
		for (size_t i = 0; i < cq.size; i++)
			out << *cq.values[i] << " ";
		out << endl;
		return out;
	}
	friend istream & operator>> (istream &in, CircleQueue<T> &cq) {
		{
			while (cq.cap != cq.size && !in.eof() && !in.fail())
			{
				T tmp;
				in >> tmp;
				if (!in.eof() && !in.fail()) {
					cq.pushBack(tmp);
				}
			}
			return in;
		}
	}
	//void Push&Sort
};

