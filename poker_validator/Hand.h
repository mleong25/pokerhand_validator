#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand {
private:
    Card cards[5];

public:
    Hand();
    Hand(Card card[]);
    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPair();
    bool isPair();
    void sortByValue();
};
#endif