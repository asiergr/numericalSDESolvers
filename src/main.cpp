#include "euler-murayama.cpp"
#include <iostream>
#include <ostream>

int main(int argc, char* argv[]) {
    int interval[2] = {3,7};
    int to_print[] = euler_murayama(interval, 1000, 0);

    for (auto x: to_print) {
        std::cout << x << std::endl;
    }
}