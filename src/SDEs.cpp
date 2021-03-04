class SDE {
    public:
        // pure virtual functions
        virtual double a(double Y_t) = 0;
        virtual double b(double Y_t) = 0;
};

class OrnsteinUhlenbeck: public SDE {
    private:
        double theta;
        double mu;
        double sigma;

    public:
        double a(double Y_t) override {
            return theta*(mu - Y_t);
        }

        double b(double Y_t) override {
            return sigma;
        }
};