#include "Card.h"

Card::Card() {
}

Card::Card(int val, Suit s) {
    value = val;
    suit = s;
}

Suit Card::getSuit() {
    return suit;
}

int Card::getValue() {
    return value;
}