#include "Transmission.h"

int main(int argc, char* argv) {

	int n_z = 10;
	float n_m = 12.5f;

	Wheel w1 = Wheel(n_z, n_m);
	Wheel w2 = Wheel(n_z, n_m);

	Shaft s1 = Shaft();

	s1.set_driven_wheel(&w1);
	s1.set_driving_wheel(&w2);

	s1.print_shaft();


	return(0);
}