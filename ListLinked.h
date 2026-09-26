#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        ListLinked() : first(nullptr), n(0) {}

	~ListLinked() override {
		while (first != nullptr) {
			Node<T>* aux = first;
			first = first->next;
			delete aux;
		}
	}

	T operator[](int pos) const {
		if (pos < 0 || pos >= n) {
			throw std::out_of_range("Posicion fuera de rango");
		}
		Node<T>* curr = first;
		for (int i = 0; i < pos; ++i) {
			curr = curr->next;
		}
		return curr->data;
	}

friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
	out << "List [";
	Node<T>* curr = list.first;
	while (curr != nullptr) {
		out << curr->data;
		if (curr->next != nullptr) {
			out << ", ";
		}
		curr = curr->next;
	}
	out << "]";
	return out;
}

void insert(int pos, T e) override {
	if (pos < 0 || pos > n){
		throw std::out_of_range("Posicion inválida para insertar");
	}
	if (pos == 0) {
		first = new Node<T>(e, first);
	}else{
		Node<T>* prev = first;
		for (int i = 0; i < pos - 1; ++i) {
			prev = prev->next;
		}
		prev->next = new Node<T>(e, prev->next);
	}
	n++;
}

void append(T e) override {
	insert(n, e);
}

void prepend(T e) override {
	insert(0, e);
}

T remove(int pos) override {
	if (pos < 0 || pos >= n) {
		throw std::out_of_range("Posicion inválida para borrar");
	}
	Node<T>* aux;
	if (pos == 0) {
		aux = first;
		first = first->next;
	} else {
		Node<T>* prev = first;
		for (int i = 0; i < pos - 1; i++) {
			prev = prev->next;
		}
		aux = prev->next;
		prev->next = aux->next;
	}
	T element = aux->data;
	delete aux;
	n--;
	return element;
}

T get(int pos) const override {
	return (*this)[pos];
}

int search(T e) const override {
	Node<T>* curr = first;
	int index = 0;
	while (curr != nullptr) {
		if (curr->data == e) return index;
		curr = curr->next;
		index++;
	}
	return -1;
}
bool empty() const override {
	return n == 0;
}

int size() const override {
	return n;
}; 
};


#endif
