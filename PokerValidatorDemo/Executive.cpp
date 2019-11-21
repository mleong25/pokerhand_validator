#include "Executive.h"

Executive::Executive(std::string filename) {
    std::ifstream inFile;
    std::string data;

    inFile.open(filename);
    int i = 0;

    if(inFile.is_open()) {
        while(inFile >> data) {
            card[i] = parse(data);
        }
    } else {
        std::cout << "Error opening filename " << filename << std::endl;
    }

    inFile.close();
}

void Executive::parse(std::string str) {
    if(str.length() == 3) {
        if((atoi)(&str.at(0)) != 10) {
            exit(-1)
        }
    } else if(str.length() == 2) {
        if((str.at(0) == 'A'
            || str.at(0) == 'J'
            || str.at(0) == 'Q'
            || str.at(0) == 'K'
            && isValidSuit(str.at(1)))) {
                return(Card(getFaceVal(str.at(0)), getSuitVal(str.at(1)))));
            }
    }
}

bool Execuitve::isValidSuit(char s) {
    if(s == 'S' || s == 'C' || s == 'D' || s == 'H') {
        return true;
    }
    std::cout << "Invalid suit.\n";
    exit(-1);
}

