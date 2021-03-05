#include "./../include/NumericalMethods.h"
#include <math.h>
#include <vector>

void NumericalMethod::euler_murayama(double out[], double interval[2], int points,
                    double x0, double (*a)(double y_t, double t), double (*b)(double y_t, double t)) {
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
      double y_i_plus = y_i + a(y_i, t)*dt + b(y_i, t) * dW;
      out[i] = y_i_plus;
    }
}

void NumericalMethod::milstein(double out[], double interval[2], int points,
                  double x0, double (*a)(double y_t, double t), double (*b)(double y_t, double t)) {
  // generate random engines
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(0.0,1.0);

  // unpacking
  double t0 = interval[0];
  double tn = interval[1];
  // dt terms
  double dt = (tn - t0) / points;

  // output
  out[0] = x0;
  // Now we are going to estimate x_1 because we need 2 initial terms for out approximation
  out[1] = x0 + distribution(generator) * sqrt(dt);

  // Stuff for our approximation of b'(y_t, t)
    std::vector<double> b_i;
    b_i.push_back(b(out[0], t0));
    b_i.push_back(b(out[1], t0 + dt));

  // Now for the actual approximation
  for (int i = 2; i < points; i++) {
    // generate noise
    double dW = distribution(generator) * sqrt(dt);
    // function
    double t = t_0 + (i - 1)*dt;
    double y_i = out[i - 1];
    double y_i_minus = out[i - 2];


    double b_prime = (b_i.at(i - 1) - b_i.at(i - 2)) / dt;


    double y_i_plus = y_i + a(y_i, t) * dt + b(y_i, t) * dt + 0.5 * 
  }
}