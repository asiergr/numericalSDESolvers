#ifndef NUMERICAL_METHODS_H
#define NUMERICAL_METHODS_H
#include "SDEs.h"
#include <cmath>
#include <random>
#include <vector>

class NumericalMethod {
    public:
        void euler_murayama(std::vector<double> out, double t0, double tn, int points,
                    double x0, double (*a)(double y_t, double t), double (*b)(double y_t, double t));

        void milstein(std::vector<double> out, double t0, double tn, int points,
                  double x0, double (*a)(double y_t, double t), double (*b)(double y_t, double t));
};
#endif