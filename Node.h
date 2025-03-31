#pragma once

#include "Utilities.h"

template <class Param>

class Node {

private:

	Param elmt;
	Node<Param>* next;

public:

	Node() : elmt(Param()), next(nullptr) {}

	Node(const Param& n_elmt) : elmt(n_elmt), next(nullptr) {}

	~Node() {
		delete(next);
	}

	Param* get_elmt() {
		return(&elmt);
	}

	Node* get_next() {
		return(next);
	}

	void set_elmt(Param p) {
		elmt = p;
	}

	void set_next(Node* n_node) {
		next = n_node;
	}

	void print_node() {
		std::cout << elmt << " ---> ";
	}
};