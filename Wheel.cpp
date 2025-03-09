#include "Wheel.h"

//----- CONSTRUCTOR -----//
Wheel::Wheel() {

	z = 0;
	d = 0.f;
	m = 0.f;
}

Wheel::Wheel(int n_z, float n_m){

	z = n_z;
	m = n_m;

	d = z * m;
}

Wheel::Wheel(int n_d, float n_m){

	d = n_d;
	m = n_m;

	if (m != 0) {
		z = d / m;
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
int Wheel::	get_z(){

	return(z);
}

float Wheel::get_d(){

	return(d);
}

float Wheel::get_m(){
	
	return(m);
}

//----- SETER -----//
void Wheel::set_z(int n_z){

	z = n_z;
	return;
}

void Wheel::set_d(float n_d){

	d = n_d;
	return;
}

void Wheel::set_m(float n_m){

	m = n_m;
	return;
}


//----- METHODS -----//
void Wheel::print_wheel() {

	std::cout << "z = " << z << std::endl;
	std::cout << "d = " << d << "_mm" << std::endl;
	std::cout << "m = " << m << "_mm" << std::endl;
}