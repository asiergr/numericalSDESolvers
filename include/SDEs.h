#ifndef SDE_H
#define SDE_H

class SDE {
    public:
        virtual double a(double Y_t, double t) = 0;
        virtual double b(double Y_t, double t) = 0;
};

class OrnsteinUhlenbeck: public SDE {
    private:
        double theta;
        double mu;
        double sigma;

    public:
        OrnsteinUhlenbeck(double theta, double mu, double sigma);
        double a(double Y_t, double t) override;
        double b(double Y_t, double t) override;
};

class BlackScholes: public SDE {
    private:
        double mu;
        double sigma;

    public:
        BlackScholes(double mu, double sigma);
        double a(double Y_t, double t) override;
        double b(double Y_t, double t) override;
};
#endif