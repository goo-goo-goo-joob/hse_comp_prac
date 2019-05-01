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
};