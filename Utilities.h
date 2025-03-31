#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <array>
#include <cmath>
#include <limits>

using namespace std;

int opti_round(float a);

void best_pair(int* n1, int* n2, int min, int max, float ratio);

#endif 