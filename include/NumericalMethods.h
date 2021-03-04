#ifndef NUMERICAL_METHODS_H
#define NUMERICAL_METHODS_H
#include "SDEs.h"
#include <cmath>
#include <random>

static void euler_murayama(double out[], int interval[2], int points, double x0, SDE sde);

#endif