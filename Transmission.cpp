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

	std::cout << "Rotation : " << rotation << std::endl;
	std::cout << "Nb shaft : " << nb_shaft << std::endl;
	std::cout << "Input speed : " << input_speed << std::endl;
	std::cout << "Output speed : " << output_speed << std::endl;
}

void Transmission::add_shaft(Shaft* n_shaft) {

	int len = get_nb_shaft();
	shaft_list.add_chain((*n_shaft), len - 1);

	return;
}

void Transmission::pop_shaft(int index) {
	Shaft s = shaft_list.pop_chain(index);
}

/*********************

create a transmission knowing the inputs :

	- number of shaft
	- inputs speed
	- output speed
	- the rotation direction of the train

*********************/

Transmission Transmission::create_gear_train(int n_nb_shaft, float n_input_speed, float n_output_speed, int n_rotation) {

	Transmission t = Transmission();

	float speed_ratio = 0.f;

	if (n_input_speed == 0.f){

		std::cout << "========================================" << std::endl;
		std::cout << "***** Null input speed *****" << std::endl;
		std::cout << "***** IMPOSSIBLE COMPUTAION *****" << std::endl;
		std::cout << "***** create_gear_train(int nb_shaft, float input_speed, float output_speed, int rotation) *****" << std::endl;
		std::cout << "========================================" << std::endl;

		return(t);
	}
	else{

		speed_ratio = n_output_speed / n_input_speed;

		if ((n_nb_shaft % 2 == 0) && (n_rotation == 1)) {

			std::cout << "========================================" << std::endl;
			std::cout << "***** rotation -1 and pair number of shaft *****" << std::endl;
			std::cout << "***** IMPOSSIBLE COMPUTAION *****" << std::endl;
			std::cout << "***** create_gear_train(int nb_shaft, float input_speed, float output_speed, int rotation) *****" << std::endl;
			std::cout << "========================================" << std::endl;

			return(t);
		}
		else {

			t.set_rotation(n_rotation);
			t.set_nb_shaft(n_nb_shaft);
			t.set_input_speed(n_input_speed);
			t.set_input_speed(n_output_speed);

			//t.shaft_list =;

			return(t);
		}
		
	}
}

Transmission Transmission::create_gear_train(float input_speed, float output_speed, int rotation) {

	Transmission t = Transmission();

	return(t);
}