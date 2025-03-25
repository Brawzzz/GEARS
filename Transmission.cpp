#pragma once

#include <iostream>

#include "Transmission.h"

//---------- CONSTRUCTOR ----------//
Transmission::Transmission() {

	rotation = 0;
	nb_shaft = 0;

	input_speed = 0.f;
	output_speed = 0.f;
}

//---------- DESTRUCTOR ----------//
Transmission::~Transmission() {}

//---------- GETER ----------//
int Transmission::get_rotation() {
	return rotation;
}

int Transmission::get_nb_shaft() {
	return nb_shaft;
}

float Transmission::get_input_speed() {
	return input_speed;
}

float Transmission::get_output_speed() {
	return output_speed;
}

ChainList<Shaft> Transmission::get_shaft_list() {
	return(shaft_list);
}

//---------- SETER ----------//
void Transmission::set_rotation(int n_rotation) {
	rotation = n_rotation;
}

void Transmission::set_nb_shaft(int n_nb_shaft) {
	nb_shaft = n_nb_shaft;
}

void Transmission::set_input_speed(float n_input_speed) {
	input_speed = n_input_speed;
}

void Transmission::set_output_speed(float n_output_speed) {
	output_speed = n_output_speed;
}

//---------- METHODS ----------//
void Transmission::print_transmission() {

	std::cout << std::endl;
	std::cout << "********************" << std::endl;
	std::cout << "Rotation : " << rotation << std::endl;
	std::cout << "Nb shaft : " << nb_shaft << std::endl;
	std::cout << "Input speed : " << input_speed << std::endl;
	std::cout << "Output speed : " << output_speed << std::endl;
	std::cout << "********************" << std::endl;
	std::cout << std::endl;

	std::cout << "//========== SHAFT LIST ==========//" << std::endl;
	shaft_list.print_chain_list();
	std::cout << "//============= END =============//" << std::endl;

}

void Transmission::add_shaft(Shaft* n_shaft) {

	int len = get_nb_shaft();

	shaft_list.add_chain((*n_shaft), len);
	nb_shaft += 1;

	return;
}

Shaft* Transmission::pop_shaft(int index) {

	Shaft* s = shaft_list.pop_chain(index);
	return s;
}

/******************************************

create a transmission knowing the inputs :

	- number of shaft
	- inputs speed
	- output speed
	- the rotation direction of the train

******************************************/

Transmission Transmission::create_gear_train(int n_nb_shaft, float n_input_speed, float n_output_speed, int n_rotation) {

	Transmission t = Transmission();

	if (n_input_speed == 0.f){

		std::cout << "========================================" << std::endl;
		std::cout << "***** Null input speed *****" << std::endl;
		std::cout << "***** IMPOSSIBLE COMPUTAION *****" << std::endl;
		std::cout << "***** create_gear_train(int nb_shaft, float input_speed, float output_speed, int rotation) *****" << std::endl;
		std::cout << "========================================" << std::endl;

		return(t);
	}
	else{

		if ((n_nb_shaft % 2 == 0) && (n_rotation == 1)) {

			std::cout << "========================================" << std::endl;
			std::cout << "***** rotation -1 and pair number of shaft *****" << std::endl;
			std::cout << "***** IMPOSSIBLE COMPUTAION *****" << std::endl;
			std::cout << "***** create_gear_train(int nb_shaft, float input_speed, float output_speed, int rotation) *****" << std::endl;
			std::cout << "========================================" << std::endl;

			return(t);
		}
		else {

			int min_nb_z = 18;
			int max_nb_z = 150;

			int driving_z = 0;
			int driven_z = 0;

			int input_shaft_rotation = 1;
			int shaft_i_rotation = input_shaft_rotation;

			float m = Wheel::MODULES[7];

			float speed_ratio = n_output_speed / n_input_speed;
			float n_ratio = powf(speed_ratio, (1.0 / n_nb_shaft));
			float n_ratio_computed = 0.f;

			float shaft_i_speed = n_input_speed;

			//========= Optimal number of theeth research ==========//
			best_pair(&driving_z, &driven_z, min_nb_z, max_nb_z, n_ratio);
			n_ratio_computed = (float)driving_z / driven_z;

			std::cout << "speed_ratio = " << speed_ratio << std::endl;
			std::cout << "n_ratio = " << n_ratio << std::endl;
			std::cout << "n_ratio_computed = " << n_ratio_computed << std::endl;
			std::cout << "driving_z = " << driving_z << std::endl << "driven_z = " << driven_z << std::endl;

			t.set_rotation(n_rotation);
			t.set_nb_shaft(n_nb_shaft);
			t.set_input_speed(n_input_speed);
			t.set_output_speed(n_output_speed);

			//========== INITIALISATION ==========//
			PWheel input_shaft_driven_wheel = new Wheel();
			PWheel input_shaft_driving_wheel = new Wheel(driving_z, m);

			Shaft* input_shaft = new Shaft(input_shaft_driven_wheel, input_shaft_driving_wheel, input_shaft_rotation, n_input_speed);

			(t.shaft_list).add_chain((*input_shaft), 0);

			//========== INSERTION ==========//
			for (int i = 1 ; i < t.nb_shaft ; i++){

				shaft_i_rotation *= -1;
				shaft_i_speed *= n_ratio_computed;

				PWheel driven_wheel = new Wheel(driven_z, m);
				PWheel driving_wheel = new Wheel(driving_z, m);

				Shaft* shaft_i = new Shaft(driven_wheel, driving_wheel, shaft_i_rotation, shaft_i_speed);

				(t.shaft_list).add_chain((*shaft_i), i);
			}

			return(t);
		}
	}
}

Transmission Transmission::create_gear_train(float n_input_speed, float n_output_speed, int n_rotation) {

	Transmission t = Transmission();

	if (n_input_speed == 0.f) {

		std::cout << "========================================" << std::endl;
		std::cout << "***** Null input speed *****" << std::endl;
		std::cout << "***** IMPOSSIBLE COMPUTAION *****" << std::endl;
		std::cout << "***** create_gear_train(int nb_shaft, float input_speed, float output_speed, int rotation) *****" << std::endl;
		std::cout << "========================================" << std::endl;

		return(t);
	}
	else {

		int min_nb_z = 18;
		int max_nb_z = 150;

		int driving_z = 0;
		int driven_z = 0;

		int input_shaft_rotation = 1;
		int shaft_i_rotation = n_rotation * input_shaft_rotation;

		float m = Wheel::MODULES[7];

		float speed_ratio = n_output_speed / n_input_speed;

		float shaft_i_speed = n_input_speed;

		t.set_rotation(n_rotation);
		t.set_input_speed(n_input_speed);
		t.set_output_speed(n_output_speed);

		return(t);
	}
}