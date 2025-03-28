#pragma once
#ifndef WHEEL_H
#define WHEEL_H
#endif

/************************************

(int)	z : Wheel's number of theeth
(int)	d : Wheel's diameter (mm)

(float)	m : Wheel's module (mm)

*************************************/

#include "Utilities.h"

class Wheel{

private:

	int z;
	int d;

	float m;
	float e;

public:

	static constexpr std::array<float, 14> MODULES = { 0.13f, 0.5f, 0.6f, 0.8f, 1.f, 1.25f, 1.5f, 2.f, 2.5f, 3.f, 4.f, 5.f, 6.f, 8.f };

	static const int Z_MIN = 18;
	static const int Z_MAX = 150;
	static const int E = 5;

	static constexpr float WHEEL_DENSITY_G_MM3 = 0.00765f;

	//----- CONSTRUCTOR -----//
	Wheel();
	Wheel(int n_z, float n_m);
	Wheel(float n_m, int n_d);

	//----- DESTRUCTOR -----//
	~Wheel();

	//----- GET -----//
	int	get_z();
	int	get_d();

	float get_m();
	float get_e();

	//----- SET -----//
	void set_z(int n_z);
	void set_d(int n_d);
	void set_m(float n_m);
	void set_e(float n_e);

	//----- METHODS -----//
	float compute_wheel_volume();

	friend std::ostream& operator<<(std::ostream& os, const Wheel& w);

};

class HelicalWheel : public Wheel{

private:

	float angle;

public:

	HelicalWheel();
	HelicalWheel(float n_angle);

	~HelicalWheel();

	float get_angle();

	void set_angle(float n_angle);
};

class StraightWheel : public Wheel{

public:

	StraightWheel();
	~StraightWheel();
};