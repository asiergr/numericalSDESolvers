#include <iostream>
#include <ostream>
#include <fstream>

#include "./../include/SDEs.h"
#include "./../include/NumericalMethods.h"

int main(int argc, char* argv[]) {

    // Initialise test variables
    double interval[2] = {3.0,7.0};
    int points = 1000;
    double out[points];
    int x0 = 0;

    // Initialise objects
    NumericalMethod nm;
    OrnsteinUhlenbeck fn(0.7, 1.5, 0.05);
    SDE* fnp = &fn;
    
    nm.euler_murayama(out, interval, points, x0, fnp);

    //open file
    std::ofstream file;
    file.open("./../results.txt");

    for (int i = 0 ; i < 1000; i++) {
        file << out[i] << std::endl;
    }
    file.close();
    return 1;
}