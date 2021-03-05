#include "./../include/NumericalMethods.h"
#include <math.h>
#include <vector>

void NumericalMethod::euler_murayama(std::vector<double> out, double t0, double tn, int points,
                    double x0, double (*a)(double y_t, double t), double (*b)(double y_t, double t)) {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(0.0,1.0);

  // dt terms
  double dt = (tn - t0) / points;

  // output
  out.push_back(x0);

  for (int i = 1; i < points; i++) {
      // generate noise
      double dW = distribution(generator) * sqrt(dt);
      // function
      double t = t0 + (i - 1)*dt;
      double y_i = out.at(i - 1);
      double y_i_plus = y_i + a(y_i, t)*dt + b(y_i, t) * dW;
      out.push_back(y_i_plus);
    }
}

void NumericalMethod::milstein(std::vector<double> out, double t0, double tn, int points,
                  double x0, double (*a)(double y_t, double t), double (*b)(double y_t, double t)) {
  // generate random engines
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(0.0,1.0);

  // dt terms
  double dt = (tn - t0) / points;

  // output
  out.push_back(x0);
  // Now we are going to estimate x_1 because we need 2 initial terms for out approximation
  out.push_back(x0 + distribution(generator) * sqrt(dt));

  // Stuff for our approximation of b'(y_t, t)
    std::vector<double> b_i;
    b_i.push_back(b(out[0], t0));
    b_i.push_back(b(out[1], t0 + dt));

  // Now for the actual approximation
  for (int i = 2; i < points; i++) {
    // generate noise
    double dW = distribution(generator) * sqrt(dt);
    // function
    double t = t0 + (i - 1)*dt;
    double y_i = out[i - 1];
    double y_i_minus = out[i - 2];

    // Approximation of b' = (b(y_i) - b(y_i-1)) / 2
    double b_prime = (b_i.at(i - 1) - b_i.at(i - 2)) / dt;

    // Calculation of y_i+1
    double y_i_plus = y_i + a(y_i, t) * dt + b(y_i, t) * dt + 0.5 * b(y_i, t) * b_prime * (dW * dW - dt);
    out.push_back(y_i_plus);
  }
}