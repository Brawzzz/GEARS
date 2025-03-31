#include "Shaft.h"

//----- CONSTRUCTOR -----//
Shaft::Shaft() {

	rotation = 0;
	angular_speed = 0.f;
	driven_wheel = nullptr;
	driving_wheel = nullptr;
}

Shaft::Shaft(PWheel n_driven_wheel, PWheel n_driving_wheel, int n_rotation, float n_angular_speed) {

	driven_wheel = n_driven_wheel;
	driving_wheel = n_driving_wheel;

	rotation = n_rotation;
	angular_speed = n_angular_speed;
}

//----- DESTRUCTOR -----//
Shaft::~Shaft() {

	delete(driven_wheel);
	delete(driving_wheel);
}

//----- GET -----//
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

//----- SET -----//
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
ostream& operator<<(ostream& os, const Shaft& s) {

	os << endl << endl << "********************" << endl;

	os << "rotation = " << s.rotation << endl;
	os << "angular_speed = " << s.angular_speed << "_tr/min" << endl;
	os << endl;

	os << "********************" << endl;

	if (s.driven_wheel && s.driving_wheel) {
		os << "driven_wheel : " << endl;
		if (auto* helical_wheel = dynamic_cast<PHelicalWheel>(s.driven_wheel)) {
			os << *helical_wheel;
		}
		else {
			os << *(s.driven_wheel);
		}
		os << "********************" << endl;

		os << "driving_wheel : " << endl;
		if (auto* helical_wheel = dynamic_cast<PHelicalWheel>(s.driving_wheel)) {
			os << *helical_wheel;
		}
		else {
			os << *(s.driving_wheel);
		}
		os << "********************" << endl;
	}
	os << endl;

	return os;
}
