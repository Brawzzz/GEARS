#pragma once

/***********************

(int)	rotation : 1 if input shaft and output shaft rotate in the same direction, -1 otherwise
(int)	nb_shaft : number of shaft in a transmission

(float)	input_speed : angular speed of the input shaft
(float)	output_speed : angular speed of the output shaft

shaft_list : list of all the shafts in a transmission

***********************/

#include "Shaft.h"
#include "ChainList.h"

class Transmission {

private:

	int rotation;
	int nb_shaft;

	float input_speed;
	float output_speed;

	ChainList<Shaft> shaft_list;

public:

	//----- CONSTRUCTOR -----//
	Transmission();

	//----- DESTRUCTOR -----//
	~Transmission();

	//------- GETER -------//

	// Changer le shaft* en template ChainList
	
	int get_rotation();
	int get_nb_shaft();
	
	float get_input_speed();
	float get_output_speed();

	ChainList<Shaft> get_shaft_list();

	//------- SETER -------//
	void set_rotation(int n_rotation);
	void set_nb_shaft(int n_tree_number);
	void set_input_speed(float n_input_speed);
	void set_output_speed(float n_output_speed);

	//----- METHODS ------//
	void print_transmission();
	void add_shaft(Shaft* n_arbre);
	void pop_shaft(int index);

	static Transmission create_gear_train(int nb_shaft, float input_speed, float output_speed, int rotation);
	static Transmission create_gear_train(float input_speed, float output_speed, int rotation);

};

