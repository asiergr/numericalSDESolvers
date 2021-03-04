#include "./../include/SDEs.h"

OrnsteinUhlenbeck::OrnsteinUhlenbeck(double theta, double mu, double sigma) {
            this->theta = theta;
            this->mu = mu;
            this->sigma = sigma;
}

double OrnsteinUhlenbeck::a(double Y_t) {
    return theta*(mu - Y_t);
}

double OrnsteinUhlenbeck::b(double Y_t) {
            return this->sigma;
}

BlackScholes::BlackScholes(double mu, double sigma) {
    this->mu = mu;
    this->sigma = sigma;
}

double BlackScholes::a(double Y_t) {
    return this->mu*Y_t;
}

double BlackScholes::b(double Y_t) {
    return Y_t*this->sigma;
}