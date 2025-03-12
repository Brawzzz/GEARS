#pragma once

#include "Wheel.h"

class Shaft {

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
	int	get_rotation();

	float get_angular_speed();

	Wheel* get_driven_wheel();
	Wheel* get_driving_wheel();

	//----- SETER -----//
	void set_rotation(int n_rotation);
	void set_angular_speed(float n_angular_speed);
	void set_driven_wheel(Wheel* n_driven_wheel);
	void set_driving_wheel(Wheel* n_driving_wheel);

	//----- METHODS -----//
	void print_shaft();

};

