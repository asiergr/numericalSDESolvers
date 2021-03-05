#include <cmath>
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>

#include "./../include/SDEs.h"
#include "./../include/NumericalMethods.h"

// Init a,b functions
double fna(double y_t, double t) {
  double mu = 0.5;
  return mu * y_t;
}
double fnb(double y_t, double t) {
  double sigma = 0.1;
  return sigma * y_t;
}

int main(int argc, char* argv[]) {

    // Initialise test variables
    double t0 = 0.0;
    double tn = 10.0;
    int points = 1000;
    std::vector<double> out;
    int x0 = 40;

    // Initialise objects
    NumericalMethod nm;
    // BlackScholes fn(1.5, 0.05);
    // double (BlackScholes::*fna) (double, double) = &BlackScholes::a;
    // double (BlackScholes::*fnb) (double, double) = &BlackScholes::b;

    nm.euler_murayama(&out, t0, tn, points, x0, &fna, &fnb);

    //open file
    std::ofstream file;
    file.open("./../results.txt");

    for (auto n: out) {
        file << n << std::endl;
    }
    file.close();
    return 1;
}