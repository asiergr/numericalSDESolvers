#include <cmath>
#include <cstdio>

static int* euler_murayama(int interval[2], int points, double x0) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0,1.0);
    // dt terms
    double dt = (interval[0] + interval[1]) / points;
    double dW = distribution(generator) * sqrt(dt);

    // params for Ornsrein-Uhlenbeck function
    double theta = 0.7;
    double mu = 1.5;
    double sigma = 0.06;

    // output
    int out[points + 1];
    out[0] = x0;

    for (int i = 1; i < points; i++) {
        double t = interval[0] + (i - 1)*dt;
        double y_i = out[i - 1];

        out[i] = y_i + (theta*(mu - y_i))*dt + sigma * dW;

    }
}