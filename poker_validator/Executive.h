#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Hand.h"
#include "Card.h"

class Executive {
private:
    Hand *hand;
public:
    Executive(std::string filename);
    Card parse(std::string str);
    bool isValidSuit(char s);
    int getFaceVal(char s);
    Suit getSuitVal(char s);
    void menu();
    void handle(int input);
};
#endif