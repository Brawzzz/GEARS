#include "Utilities.h"

int opti_round(float a){

	int opti_round_a = 0;

	float floor_a = floor(a);
	float dec_part = a - floor_a;

	opti_round_a = (int)floor_a;
	dec_part > 0.5 ? opti_round_a++ : opti_round_a;

	return opti_round_a;
}

void best_pair(int* n1, int* n2, int min, int max, float ratio) {

	int n1_copy = 0;
	int n2_copy = 0;
	
	float error = 0.f;
	float error_min = numeric_limits<float>::max();
	float current_ratio = 0.f;

	for (int i = min ; i < max ; i++){
		
		n1_copy = i;
		
		if (ratio > 1) {

			for (int j = min ; j < i ; j++) {

				n2_copy = j;
				current_ratio = (float)n1_copy / n2_copy;
				error = fabs(current_ratio - ratio);

				if (error < error_min) {
					error_min = error;

					*n1 = n1_copy;
					*n2 = n2_copy;
				}
			}
		}
		else {
			for (int j = i ; j < max ; j++) {

				n2_copy = j;
				current_ratio = (float)n1_copy / n2_copy;
				error = fabs(current_ratio - ratio);

				if (error < error_min) {
					error_min = error;

					*n1 = n1_copy;
					*n2 = n2_copy;
				}
			}
		}
	}
}