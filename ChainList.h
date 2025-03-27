#pragma once

#include "Node.h"

template <class Param> 

class ChainList {

using PNode = Node<Param>*;

private :

	PNode head;

public :

	ChainList() {
		head = nullptr;
	}

	~ChainList() {}

	PNode get_head() {
		return head;
	}

	Param* get_node_i(int index) {

		PNode current = head;

		for (int i = 0 ; i < index ; i++) {
			current = current->get_next();
		}

		return(current->get_elmt());
	}

	int get_len() {

		int size = 0;

		if (head == nullptr) {
			return(size);
		}
		else{

			PNode current = head;

			while (current != nullptr) {
				current = current->get_next();
				size++;
			}
			
			return(size);
		}
	}

	void print_chain_list() {

		PNode current = head;

		while (current != nullptr) {
			current->print_node();
			current = current->get_next();
		}
		std::cout << "NULL" << std::endl;
	}

	void add_chain(const Param& p, int index) {

		PNode new_node = new Node<Param>(p);

		int len = get_len();

		if (index > len) {

			delete(new_node);
			std::cout << "***** list.len < index *****" << std::endl;

			return;
		}
		else if (head == nullptr) {

			new_node->set_next((PNode)nullptr);
			head = new_node;
		}
		else if (index == 0) {

			new_node->set_next(head);
			head = new_node;
		}
		else {

			PNode current = head;

			for (int i = 0 ; i < index-1; i++){
				current = current->get_next();
			}
			new_node->set_next(current->get_next());
			current->set_next(new_node);
		}
	}

	Param* pop_chain(int index) {

		Param* p;

		if (head == nullptr || index > get_len()) {
			p = NULL;
		}

		PNode current = head;
		PNode temp_node = head;
		 
		if (index == 0) {

			head = current->get_next();
			p = current->get_elmt();
		}
		else {

			for (int i = 0 ; i < index-1 ; i++){
				current = current->get_next();
			}
			temp_node = current->get_next();
			current->set_next(temp_node->get_next());

			p = temp_node->get_elmt();
			delete(temp_node);
		}

		return(p);
	}
};
