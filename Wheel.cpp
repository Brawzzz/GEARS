#include "Wheel.h"

//----- CONSTRUCTORS -----//
Wheel::Wheel() {

	z = 0;
	d = 0;

	m = 0.f;
	e = 0.f;
}

Wheel::Wheel(int n_z, float n_m) {

	z = n_z;
	m = n_m;

	d = opti_round(z * m);
	e = 0.f;
}

Wheel::Wheel(float n_m, int n_d) {

	d = n_d;
	m = n_m;
	z = 0;
	e = 0.f;

	if (m != 0) {
		z = opti_round(d / m);
	}
	else {
		cout << "========================================" << endl;
		cout << "*** Wheel(int n_d, float n_m)***" << endl;
		cout << "Z COMPUTATION IMPOSSIBLE (M = 0)" << endl;
		cout << "========================================" << endl;
	}
}

//----- DESTRUCTOR -----//
Wheel::~Wheel() {}


//----- GET -----//
int Wheel::get_z() {
	return(z);
}

int Wheel::get_d() {
	return(d);
}

float Wheel::get_m() {
	return(m);
}

float Wheel::get_e() {
	return(e);
}

//----- SET -----//
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

void Wheel::set_e(float n_e) {
	e = n_e;
	return;
}

//----- METHODS -----//
ostream& operator<<(ostream& os, const Wheel& w) {

	os << "z = " << w.z << endl;
	os << "d = " << w.d << "_mm" << endl;
	os << "m = " << w.m << "_mm" << endl;

	return os;
}