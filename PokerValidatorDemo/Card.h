#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

// Enumeration of each suit in a card class
enum Suit {
    SPADES = 0,
    CLUBS = 1,
    HEARTS = 2,
    DIAMONDS = 3
};

class Card {
private:
    Suit suit;
    int value;

public:
    Card();
    Card(int val, Suit s);
    Suit getSuit();
    int getValue();
};
#endif