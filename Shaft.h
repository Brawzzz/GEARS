#pragma once
#ifndef SHAFT_H
#define SHAFT_H

/*************************************************

(int)		rotation : Direction of shaft rotation

(float)		angular_speed : shaft's angular speed

(Wheel*)	driven_wheel : shaft's driven wheel	
(Wheel*)	driving_wheel : shaft's driving wheel	

*************************************************/

#include "Wheel.h"
#include "StraightWheel.h"
#include "HelicalWheel.h"

using PWheel = Wheel*;
using PStraightWheel = StraightWheel*;
using PHelicalWheel = HelicalWheel*;

class Shaft {

private:

	int rotation;

	float angular_speed;

	PWheel driven_wheel;
	PWheel driving_wheel;

public:

	static const int NB_SHAFT_MIN = 2;
	static const int NB_SHAFT_MAX = 20;

	//----- CONSTRUCTOR -----//
	Shaft();
	Shaft(PWheel n_driven_wheel, PWheel n_driving_wheel, int n_rotation, float n_angular_speed);

	//----- DESTRUCTOR -----//
	~Shaft();

	//----- GET -----//
	int	get_rotation();

	float get_angular_speed();

	PWheel get_driven_wheel();
	PWheel get_driving_wheel();

	//----- SET -----//
	void set_rotation(int n_rotation);
	void set_angular_speed(float n_angular_speed);
	void set_driven_wheel(PWheel n_driven_wheel);
	void set_driving_wheel(PWheel n_driving_wheel);

	//----- METHODS -----//
	friend ostream& operator<<(ostream& os, const Shaft& s);
};

#endif
