#include "Shaft.h"

//----- CONSTRUCTOR -----//
Shaft::Shaft() {

	driven_wheel = new Wheel();
	driving_wheel = new Wheel();
}

Shaft::Shaft(Wheel* n_driven_wheel, Wheel* n_driving_wheel) {

	driven_wheel = n_driven_wheel;
	driving_wheel = n_driving_wheel;
}

//----- DESTRUCTOR -----//
Shaft::~Shaft() {

	delete(driven_wheel);
	delete(driving_wheel);
}

//----- GETER -----//


//----- SETER -----//


//----- METHODS -----//
void Shaft::print_shaft() {

}
