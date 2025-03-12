#pragma once

#include "Shaft.h"
#include "ChainList.h"

class Transmission {
private:

	/*
		rotation :


	*/

	int rotation;
	int tree_number;

	float entry_speed;
	float exit_speed;

	// ramener la template de classe shaft

public:

	//----- CONSTRUCTOR -----//
	Transmission();

	//----- DESTRUCTOR -----//
	~Transmission();

	//----- GETER -----//

	// Changer le shaft* en template ChainList
	Shaft* getArbres();
	int get_rotation();
	int get_tree_number();
	float get_entry_speed();
	float get_exit_speed();

	//----- SETER -----//
	void set_rotation(int n_rotation);
	void set_tree_number(int n_tree_number);
	void set_entry_speed(float n_entry_speed);
	void set_exit_speed(float n_exit_speed);

	//----- METHODS -----//
	void print_transmission();
	void retraitArbre(int n_rg_arbre);
	void ajoutArbre(Shaft* n_arbre);
};

