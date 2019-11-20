#include <iostream>

#include "Executive.h"

int main(int argc, char** argv) {
    if(argc > 1) {
        Executive run(argv[1]);
    } else {
        std::cout << "Error: invalid terminal arguments.\n";
    }
}