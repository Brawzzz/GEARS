#include "Transmission.h"

int main(int argc, char* argv) {

	int n_nb_shaft = 4;
	int n_rotation = -(int)pow((-1.0), n_nb_shaft);

	std::cout << n_rotation << std::endl;

	float n_input_speed = 20.f;
	float n_output_speed = 10.f;

	Transmission t = Transmission::create_gear_train(n_nb_shaft, n_input_speed, n_output_speed, n_rotation);

	t.print_transmission();

	return(0);
}