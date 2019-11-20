#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

enum Suit
{
    SPADES = 0,          // Enumeration of Spades
    CLUBS = 1,          // Enumeration of Clubs
    HEARTS = 2,          // Enumeration of Hearts
    DIAMONDS = 3           // Enumeration of Diamonds
};

class Card
{
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
