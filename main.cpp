#include "Transmission.h"

int main(int argc, char* argv) {

	int n_rotation = 1;

	float n_angular_speed = 100.0f;
	
	PHelicalWheel ws1 = new HelicalWheel();
	PHelicalWheel ws2 = new HelicalWheel();

	Shaft s = Shaft(ws1, ws2, n_rotation, n_angular_speed);
	cout << s << endl;

	//-------------------------------------------------------------------------------------------------------------------------------//

	/******************************************

		create a transmission knowing :

		- number of shaft
		- inputs speed
		- output speed
		- the rotation direction of the train

	******************************************/

	cout << "//------------------------------------------------------------------------------------//" << endl;
	cout << "//-------------- INSTANCIATE A TRANSMISSION KNOWING THE NUMBER OF SHAFT --------------//" << endl;
	cout << "//------------------------------------------------------------------------------------//" << endl;

	int n_nb_shaft = 4;

	float n_input_speed = 20;
	float n_output_speed = 10;

	n_rotation = -(int)pow((-1.0), n_nb_shaft);

	Transmission t1 = Transmission::create_gear_train(n_nb_shaft, n_input_speed, n_output_speed, n_rotation);

	t1.print_transmission();

	//-------------------------------------------------------------------------------------------------------------------------------//

	/******************************************

		create a transmission knowing :

		- inputs speed
		- output speed
		- the rotation direction of the train

		Which minimze the train's mass

	******************************************/

	cout << "//---------------------------------------------------------------------------------------------//" << endl;
	cout << "//-------------- INSTANCIATE A TRANSMISSION WHITHOUT KNOWING THE NUMBER OF SHAFT --------------//" << endl;
	cout << "//---------------------------------------------------------------------------------------------//" << endl;

	n_rotation = 1;

	n_input_speed = 20;
	n_output_speed = 10;

	int nb_shaft_computed = 0;

	float min_mass_computed = 0.f;

	Transmission t2 = Transmission::create_gear_train(n_input_speed, n_output_speed, n_rotation, &nb_shaft_computed, &min_mass_computed);

	t2.print_transmission();

	cout << "mass of t2 = " << min_mass_computed << "_g" << endl;

	return(0);
}