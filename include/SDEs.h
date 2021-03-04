class SDE {
    public:
        virtual double a(double Y_t) = 0;
        virtual double b(double Y_t) = 0;
};

class OrnsteinUhlenbeck: public SDE {
    private:
        double theta;
        double mu;
        double sigma;

    public:
        OrnsteinUhlenbeck(double theta, double mu, double sigma);
        double a(double Y_t);
        double b(double Y_t);
};

class BlackScholes: public SDE {
    private:
        double mu;
        double sigma;

    public:
        BlackScholes(double mu, double sigma);
        double a(double Y_t);
        double b(double Y_t);
};