#include <iostream>

#include "Executive.h"

// Takes input from the terminal
// argc, number of terminal arguments
// argv, the arguments themselves
int main(int argc, char** argv) {
    if(argc > 1) {
        // take the argument, in this case the file
        Executive run(argv[1]);
    } else {
        std::cout << "Error: invalid terminal arguments.\n";
    }
}