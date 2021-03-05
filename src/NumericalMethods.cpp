#include "./../include/NumericalMethods.h"

void NumericalMethod::euler_murayama(double out[], double interval[2],
                            int points, double x0, SDE* sde) {

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0,1.0);

    // unpacking
    double t_0 = interval[0];
    double t_n = interval[1];
    // dt terms
    double dt = (t_n - t_0) / points;

    // output
    out[0] = x0;

    for (int i = 1; i < points; i++) {
        // generate noise
        double dW = distribution(generator) * sqrt(dt);

        // function
        double t = t_0 + (i - 1)*dt;
        double y_i = out[i - 1];
        double result = y_i + sde->a(y_i, t)*dt + sde->b(y_i, t) * dW;

        out[i] = result;

    }
}