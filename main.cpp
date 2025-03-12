#include "Wheel.h"
#include "ChainList.h"

int main(int argc, char* argv) {

	// Wheel w1 = Wheel();

	ChainList<int> list;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	int index = 1;

	list.add_chain(a, 0);
	list.add_chain(b, 1);
	list.add_chain(c, 2);
	list.print_chain_list();

	int r = list.pop_chain(index);
	list.print_chain_list();

	return(0);
}