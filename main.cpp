#include "Transmission.h"

int main(int argc, char* argv) {

	int n_z = 10;
	float n_m = 12.5f;

	PWheel w1 = new Wheel(n_z, n_m);
	PWheel w2 = new Wheel(n_z, n_m);

	Shaft s1 = Shaft();

	s1.set_driven_wheel(w1);
	s1.set_driving_wheel(w2);

	std::cout << s1;

	ChainList<Shaft> t;

	t.add_chain(s1, 0);

	return(0);
}