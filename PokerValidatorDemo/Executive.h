#ifndef EXECUTIVE_H
#define  EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>

class Executive {
private:
    Hand *hand;
public:
    Executive();
    Executive(std::string filename);
    void parse(std::string str);
    bool isValidSuit(char s);
    Suit getSuitVal(char s);
    int getFaceVal(char s);
};
#endif