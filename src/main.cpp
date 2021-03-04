#include <iostream>
#include <ostream>
#include <fstream>

#include "SDEs.h"
#include "NumericalMethods.h"

int main(int argc, char* argv[]) {

    double interval[2] = {3.0,7.0};
    int points = 1000;
    double out[points];
    int x0 = 0;

    OrnsteinUhlenbeck fn(0.3, 0.4, 0.5);
    
    euler_murayama(out, interval, points, x0, fn);

    //open file
    std::ofstream file;
    file.open("./../resulsts.txt");

    for (int i = 0 ; i < 1000; i++) {
        file << out[i] << std::endl;
    }
    file.close();
    return 1;
}