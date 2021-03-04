#include <cmath>
#include <random>
#include "Numerical-SDE-Methods.h"
#include "SDEs.h"



static void euler_murayama(double out[], double interval[2],
                            int points, double x0, SDE sde) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0,1.0);
    // unpacking
    double t_0 = interval[0];
    double t_n = interval[1];
    // dt terms
    double dt = (t_n - t_0) / points;
    

    // params for Ornsrein-Uhlenbeck function
    double theta = 0.7;
    double mu = 1.5;
    double sigma = 0.06;

    // output
    out[0] = x0;

    for (int i = 1; i < points; i++) {
        // generate noise
        double dW = distribution(generator) * sqrt(dt);

        // function
        double t = t_0 + (i - 1)*dt;
        double y_i = out[i - 1];
        double result = y_i + (theta*(mu - y_i))*dt + sigma * dW;

        out[i] = result;

    }
}