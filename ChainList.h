#pragma once

template <class Param> 

class ChainList {

private :

	struct Node {

		Param elmt;
		Node* next;
	};
	using PNode = Node*;

	PNode head;

public :

	ChainList() {
		head = nullptr;
	}

	~ChainList() {

		PNode current = head;

		while (current) {
			PNode node_i = current;

			current = current->next;
			delete(node_i);
		}
	}

	PNode get_head() {
		return head;
	}

	Param get_node_i(int index) {

		PNode current = head;

		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		return current->elmt;
	}

	int get_len() {

		int size = 0;

		if (head == nullptr) {
			return(size);
		}
		else{

			PNode current = head;

			while (current != nullptr) {
				current = current->next;
				size++;
			}
			
			return(size);
		}
	}

	void print_chain_list() {

		PNode current = head;

		while (current != nullptr) {
			std::cout << current->elmt << " -> ";
			current = current->next;
		}
		std::cout << "NULL" << std::endl;
	}

	void add_chain(Param p, int index) {

		PNode new_node = new Node();
		new_node->elmt = p;

		int len = get_len();

		if (index > len) {

			delete(new_node);
			std::cout << "***** list.len < index *****" << std::endl;

			return;
		}
		else if (head == nullptr) {

			new_node->next = nullptr;
			head = new_node;
		}
		else if (index == 0) {

			new_node->next = head;
			head = new_node;
		}
		else {

			PNode current = head;

			for (int i = 0 ; i < index-1; i++){
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}

	Param pop_chain(int index) {

		Param p = (*new Param());

		if (head == nullptr || index > get_len()) {
			return(p);
		}

		PNode current = head;
		PNode temp_node = nullptr;
		 
		if (index == 0) {

			head = current->next;
			p = current->elmt;
			delete(current);

			return(p);
		}
		else {

			for (int i = 0 ; i < index-1 ; i++){
				current = current->next;
			}
			temp_node = current->next;
			current->next = temp_node->next;

			p = temp_node->elmt;
			delete(temp_node);

			return(p);
		}
	}
};
