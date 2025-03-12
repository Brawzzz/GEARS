#pragma once

#include <iostream>

#include "Transmission.h"

//----- CONSTRUCTOR -----//
Transmission::Transmission() {

	rotation = 0;
	tree_number = 0;
	entry_speed = 0.f;
	exit_speed = 0.f;
}

//----- DESTRUCTOR -----//
Transmission::~Transmission() {

}

//----- GETER -----//
// Changer le shaft* en chainlist
// Shaft* Transmission::getArbres() {
//     return arbres;
// }

int Transmission::get_rotation() {
	return rotation;
}

int Transmission::get_tree_number() {
	return tree_number;
}

float Transmission::get_entry_speed() {
	return entry_speed;
}

float Transmission::get_exit_speed() {
	return exit_speed;
}

//----- SETER -----//
void Transmission::set_rotation(int n_rotation) {
	rotation = n_rotation;
}

void Transmission::set_tree_number(int n_tree_number) {
	tree_number = n_tree_number;
}

void Transmission::set_entry_speed(float n_entry_speed) {
	entry_speed = n_entry_speed;
}

void Transmission::set_exit_speed(float n_exit_speed) {
	exit_speed = n_exit_speed;
}

//----- METHODS -----//
void Transmission::print_transmission() {

	std::cout << "Rotation : " << rotation << std::endl;
	std::cout << "Tree number : " << tree_number << std::endl;
	std::cout << "Entry speed : " << entry_speed << std::endl;
	std::cout << "Exit speed : " << exit_speed << std::endl;
}

// void Transmission::retraitArbre(int n_rg_arbre) {

//     arbres->remove(n_rg_arbre);
//     // Utiliser popchain de ChainList pour retirer un arbre
// }
