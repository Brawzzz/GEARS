#pragma once

/***********************

(int)	z : Wheel's number of theeth
(int)	d : Wheel's diameter (mm)

(float)	m : Wheel's module (mm)

***********************/

#include <iostream>
#include <array>

#include "Utilities.h"

class Wheel{

private:

	int z;
	int d;

	float m;
	float e;

public:

	static const std::array<float, 14> MODULES;
	static const float WHEEL_DENSITY;

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
	float get_e();

	//----- SETER -----//
	void set_z(int n_z);
	void set_d(int n_d);
	void set_m(float n_m);
	void set_e(float n_e);

	//----- METHODS -----//
	
	//----- SURCHARGE -----//
	friend std::ostream& operator<<(std::ostream& os, const Wheel& w);

};