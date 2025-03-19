#include "Shaft.h"

//----- CONSTRUCTOR -----//
Shaft::Shaft() {

	rotation = 0;
	angular_speed = 0.f;
	driven_wheel = new Wheel();
	driving_wheel = new Wheel();
}

Shaft::Shaft(PWheel n_driven_wheel, PWheel n_driving_wheel) {

	driven_wheel = n_driven_wheel;
	driving_wheel = n_driving_wheel;

	rotation = 0;
	angular_speed = 0.f;
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

PWheel Shaft::get_driven_wheel() {
	return driven_wheel;
}

PWheel Shaft::get_driving_wheel() {
	return driving_wheel;
}

//----- SETER -----//
void Shaft::set_rotation(int n_rotation) {
	rotation = n_rotation;
}

void Shaft::set_angular_speed(float n_angular_speed) {
	angular_speed = n_angular_speed;
}

void Shaft::set_driven_wheel(PWheel n_driven_wheel) {
	driven_wheel = n_driven_wheel;
}

void Shaft::set_driving_wheel(PWheel n_driving_wheel) {
	driving_wheel = n_driving_wheel;
}

//----- METHODS -----//
std::ostream& operator<<(std::ostream& os, const Shaft& s) {


	os << "********************" << std::endl;

	os << "rotation = " << s.rotation << std::endl;
	os << "angular_speed = " << s.angular_speed << "_tr/min" << std::endl;
	os << std::endl;

	os << "********************" << std::endl;
	os << "driven_wheel = " << std::endl;
	os << *(s.driven_wheel);
	os << "********************" << std::endl;

	os << "driving_wheel = " << std::endl;
	os << *(s.driving_wheel);
	os << "********************" << std::endl;

	os << std::endl;

	return os;
}
