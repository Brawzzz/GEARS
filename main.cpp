#include "Transmission.h"

int main(int argc, char* argv) {

	//-------------- INSTANCIATE A TRANSMISSION KNOWING THE NUMBER OF SHAFT --------------//
	std::cout << "//------------------------------------------------------------------------------------//" << std::endl;
	std::cout << "//-------------- INSTANCIATE A TRANSMISSION KNOWING THE NUMBER OF SHAFT --------------//" << std::endl;
	std::cout << "//------------------------------------------------------------------------------------//" << std::endl;

	int n_nb_shaft = 4;
	int n_rotation = -(int)pow((-1.0), n_nb_shaft);

	float n_input_speed = 20;
	float n_output_speed = 10;

	Transmission t1 = Transmission::create_gear_train(n_nb_shaft, n_input_speed, n_output_speed, n_rotation);

	t1.print_transmission();

	//-------------- INSTANCIATE A TRANSMISSION WHITHOUT KNOWING THE NUMBER OF SHAFT --------------//
	std::cout << "//---------------------------------------------------------------------------------------------//" << std::endl;
	std::cout << "//-------------- INSTANCIATE A TRANSMISSION WHITHOUT KNOWING THE NUMBER OF SHAFT --------------//" << std::endl;
	std::cout << "//---------------------------------------------------------------------------------------------//" << std::endl;

	n_rotation = 1;

	n_input_speed = 20;
	n_output_speed = 10;

	int nb_shaft_computed = 0;

	float min_mass_computed = 0.f;

	Transmission t2 = Transmission::create_gear_train(n_input_speed, n_output_speed, n_rotation, &nb_shaft_computed, &min_mass_computed);

	// t2.print_transmission();

	std::cout << "mass of t2 = " << min_mass_computed << "_g" << std::endl;

	return(0);
}