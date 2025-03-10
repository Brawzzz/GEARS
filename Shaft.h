#pragma once

#include "Wheel.h"

class Shaft{

private:

	int rotation;

	float angular_speed;

	Wheel* driven_wheel;
	Wheel* driving_wheel;

public:

	//----- CONSTRUCTOR -----//
	Shaft();

	Shaft(Wheel* n_driven_wheel, Wheel* n_driving_wheel);

	//----- DESTRUCTOR -----//
	~Shaft();

	//----- GETER -----//

	//----- SETER -----//

	//----- METHODS -----//
	void print_shaft();

};

