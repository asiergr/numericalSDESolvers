#include "Numerical-SDE-Methods.cpp"
#include <iostream>
#include <ostream>

int main(int argc, char* argv[]) {

    double interval[2] = {3.0,7.0};
    int points = 1000;
    double out[points];
    int x0 = 0;
    
    euler_murayama(out, interval, points, x0);

    for (int i = 0 ; i < 1000; i++) {
        std::cout << out[i] << std::endl;
    }
}