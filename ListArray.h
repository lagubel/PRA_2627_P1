#ifndef LISTARRAY_H
#define LISTARRAY_H
#include "List.h"
#include <stdexcept>
#include <ostream>

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MIN_CAPACITY = 2;

		void resize (int new_capacity) {
			T* new_arr = new T[new_capacity];
			for (int i = 0; i < n; ++i) {
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_capacity;
		}
	
	public:
		ListArray() {
			arr = new T[MIN_CAPACITY];
			max = MIN_CAPACITY;
			n = 0;
		}
		 ~ListArray() override {
			 delete[] arr;
		 }

		 T operator[](int pos) const {
			 if(pos < 0 || pos >= n) {
				throw std::out_of_range("Posicion fuera de rango");
			 }
		 return arr[pos];
		 }
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &List) {
out << "List [";
for (int i = 0; i < List.n; ++i) {
	out << List.arr[i];
	if (i < List.n - 1) {
		out << ", ";
	}
}
out << "]";
return out;
}

void insert(int pos, T e) override {
	if(pos < 0 || pos > n) {
		throw std::out_of_range("Posicion inválida para insertar");
	}
	if (n == max) {
		resize(max * 2);
	}
	for (int i = n; i > pos; --i) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = e;
	n++;
}

void append(T e) override {
	insert(n, e);
}

void prepend(T e) override {
	insert(0, e);
}

T remove(int pos) override {
	if (pos < 0 || pos >= n){
		throw std::out_of_range("Posicion inválida para borrar");
	}
	T element = arr[pos];
	for (int i = pos; i < n - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	n--;
	return element;
}

T get(int pos) const override {
	return (*this)[pos];
}

int search(T e) const override {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == e) return i;
	}
	return -1;
}

bool empty() const override {
	return n == 0;
}

int size() const override {
	return n;
}
};

#endif
