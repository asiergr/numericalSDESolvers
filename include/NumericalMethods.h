#ifndef NUMERICAL_METHODS_H
#define NUMERICAL_METHODS_H
#include "SDEs.h"
#include <cmath>
#include <random>

class NumericalMethod {
    public:
        void euler_murayama(double out[], double interval[2], int points, double x0, SDE* sde);
        void milstein(double out[], double interval[2],
                          int points, double x0, SDE* sde);
};
#endif