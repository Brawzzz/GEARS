#pragma once

#include <iostream>

class Wheel{

private:

	/*
		z : Wheel's number of theeth
		d : Wheel's diameter (mm)
		m : Wheel's module (mm)
	*/

	int z;

	float d;
	float m;

public:

	//----- CONSTRUCTOR -----//
	Wheel();

	Wheel(int n_z, float n_m);
	Wheel(float n_m, int n_d);

	//----- DESTRUCTOR -----//
	~Wheel();

	//----- GETER -----//
	int	get_z();
	int	get_d();
	float get_m();

	//----- SETER -----//
	void set_z(int n_z);
	void set_d(int n_d);
	void set_m(float n_m);

	//----- METHODS -----//
	void print_wheel();

};