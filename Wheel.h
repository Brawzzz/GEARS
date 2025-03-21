#pragma once

/***********************

(int)	z : Wheel's number of theeth
(int)	d : Wheel's diameter (mm)

(float)	m : Wheel's module (mm)

***********************/

#include <iostream>

#include "Utilities.h"

class Wheel{

private:

	int z;
	int d;

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
	
	//----- SURCHARGE -----//
	friend std::ostream& operator<<(std::ostream& os, const Wheel& w);

};