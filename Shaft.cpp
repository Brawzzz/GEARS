#include "Shaft.h"

//----- CONSTRUCTOR -----//
Shaft::Shaft() {

	rotation = 0;
	angular_speed = 0.f;
	driven_wheel = new Wheel();
	driving_wheel = new Wheel();
}

Shaft::Shaft(Wheel* n_driven_wheel, Wheel* n_driving_wheel) {

	driven_wheel = n_driven_wheel;
	driving_wheel = n_driving_wheel;
}

//----- DESTRUCTOR -----//
Shaft::~Shaft() {

	delete(driven_wheel);
	delete(driving_wheel);
}

//----- GETER -----//
int Shaft::get_rotation() {
	return rotation;
}

float Shaft::get_angular_speed() {
	return angular_speed;
}

Wheel* Shaft::get_driven_wheel() {
	return driven_wheel;
}

Wheel* Shaft::get_driving_wheel() {
	return driving_wheel;
}

//----- SETER -----//
void Shaft::set_rotation(int n_rotation) {
	rotation = n_rotation;
}

void Shaft::set_angular_speed(float n_angular_speed) {
	angular_speed = n_angular_speed;
}

void Shaft::set_driven_wheel(Wheel* n_driven_wheel) {
	driven_wheel = n_driven_wheel;
}

void Shaft::set_driving_wheel(Wheel* n_driving_wheel) {
	driving_wheel = n_driving_wheel;
}

//----- METHODS -----//
void Shaft::print_shaft() {

	std::cout << "rotation = " << rotation << std::endl;
	std::cout << "angular_speed = " << angular_speed << "_mm" << std::endl;
	std::cout << "driven_wheel = " << std::endl;
	(*driven_wheel).print_wheel();
	std::cout << "driving_wheel = " << std::endl;
	(*driving_wheel).print_wheel();
}
