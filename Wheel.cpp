#include "Wheel.h"

//----- CONSTRUCTOR -----//
Wheel::Wheel() {

	z = 0;
	d = 0;
	m = 0.f;
}

Wheel::Wheel(int n_z, float n_m) {

	z = n_z;
	m = n_m;

	d = opti_round(z * m);
}

Wheel::Wheel(float n_m, int n_d) {

	d = n_d;
	m = n_m;
	z = 0;

	if (m != 0) {
		z = opti_round(d / m);
	}
	else {
		std::cout << "========================================" << std::endl;
		std::cout << "*** Wheel(int n_d, float n_m)***" << std::endl;
		std::cout << "Z COMPUTATION IMPOSSIBLE (M = 0)" << std::endl;
		std::cout << "========================================" << std::endl;
	}
}

//----- DESTRUCTOR -----//
Wheel::~Wheel() {}


//----- GETER -----//
int Wheel::get_z() {
	return(z);
}

int Wheel::get_d() {
	return(d);
}

float Wheel::get_m() {
	return(m);
}

//----- SETER -----//
void Wheel::set_z(int n_z) {
	z = n_z;
	return;
}

void Wheel::set_d(int n_d) {
	d = n_d;
	return;
}

void Wheel::set_m(float n_m) {
	m = n_m;
	return;
}

//----- METHODS -----//


//----- SURCHARGE -----//
std::ostream& operator<<(std::ostream& os, const Wheel& w) {

	os << "z = " << w.z << std::endl;
	os << "d = " << w.d << "_mm" << std::endl;
	os << "m = " << w.m << "_mm" << std::endl;

	return os;
}