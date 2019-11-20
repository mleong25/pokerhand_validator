#include "Hand.h"

Hand::Hand(Card card[]) {
    for(int i = 0; i < 5; i++) {
        cards[i] = card[i];
    }
}

bool Hand::isRoyalFlush() {
    bool hasA = false, hasK = false, hasQ = false, hasJ = false, has10 = false;
    for(int i = 0; i < 5; i++) {
        // Check for the same suit in all the cards
        if(i+1 < 5 && cards[i].getSuit() != cards[i+1].getSuit()) {
            std::cout << "Better luck next time! It's only a 1 : 649,739 chance.\n";
            return false;
        }
        // Check for A, K, Q, J, 10
        if(cards[i].getValue() == 1) {
            hasA = true;
        }
        if (cards[i].getValue() == 13) {
            hasK = true;
        }
        if (cards[i].getValue() == 12) {
            hasQ = true;
        }
        if (cards[i].getValue() == 11) {
            hasJ = true;
        }
        if (cards[i].getValue() == 10) {
            has10 = true;
        }
    }
    if(has10 && hasA && hasJ && hasK && hasQ) {
        std::cout << "Congrats!! You are 649,739 : 1. You should go to Vegas, but this might be all the luck you've spent.\n";
        return true;
    }
    std::cout << "Better luck next time! It's only a 1 : 649,739 chance.\n";
    return false;
}

bool Hand::isStraightFlush() {
    /* if(isStraight() && isFlush()) {
        return true;
    } */
    sortByValue();
    for(int i = 0; i < 5; i++) {
        // Check for the same suit in all the cards
        if(i+1 < 5 && cards[i].getSuit() != cards[i+1].getSuit()) {
            std::cout << "You don't have the suits, sorry!\n";
            return false;
        }
        if(i+1 < 5 && cards[i+1].getValue() != cards[i].getValue() + 1) {
            std::cout << "You don't have the sequence, sorry!\n";
            return false;
        }
    }
    return true;
}

bool Hand::isFourOfAKind() {
    int count = 0, cardVal;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (cards[i].getValue() == cards[j].getValue()) {
                cardVal = cards[i].getValue();
                count++;
                if(count == 4) {
                    std::cout << "Nice 4-pair of " << cardVal << "'s.\n";
                    return true;
                }
            }
        }   
    }
    std::cout << "Not a 4-of-a-kind today, but maybe some smaller pairs?\n";
    return false;
}

bool Hand::isFullHouse() {
    if(isThreeOfAKind() && isPair()) {
        std::cout << "It's a pretty packed house in here.\n";
        return true;
    }
    std::cout << "Looks like you're living alone for a while.\n";
    return false;
}

bool Hand::isFlush() {
    sortByValue();
    int highCard = cards[4].getValue();
    for(int i = 0; i < 5; i++) {
        // Check for the same suit in all the cards
        if(i+1 < 5 && cards[i].getSuit() != cards[i+1].getSuit()) {
            std::cout << "The only flush you're getting is with your hopes and dreams.\n";
            return false;
        }
    }
    std::cout << "Nice flush! " << highCard << " high.\n";
    return true;
}

bool Hand::isStraight() {
    sortByValue();
    for(int i = 0; i < 5; i++) {
        if(i+1 < 5 && cards[i+1].getValue() != cards[i].getValue() + 1) {
            std::cout << "Sorry, you're shooting sideways.\n";
            return false;
        }
    }
    std::cout << "Nice straight!\n";
    return true;
}

bool Hand::isThreeOfAKind() {
    int count = 0, three;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (cards[i].getValue() == cards[j].getValue()) {
                three = cards[i].getValue();
                count++;
                if(count >= 3) {
                    std::cout << "Nice 3 of a kind of " << three << "'s!\n";
                    return true;
                }
            }
        }   
    }
    std::cout << "No 3 of a kinds, but you might have a pair or two!\n";
    return false;
}

bool Hand::isTwoPair() {
    sortByValue();
    int pairCount = 0, count = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(cards[i].getValue() == cards[j].getValue()) {
                count++;
                if(count == 2) {
                    pairCount++;
                    count = 0;
                }
            }
        }
    }
    if(pairCount == 2) {
        std::cout << "Nice 2 pair!\n";
        return true;
    }
    std::cout << "Sorry, you might still have a pair.\n";
    return false;
}

bool Hand::isPair() {
    int count = 0, cardVal;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (cards[i].getValue() == cards[j].getValue()) {
                cardVal = cards[j].getValue();
                count++;
                if(count >= 2) {
                    std::cout << "Pair of " << cardVal << "'s. Not the worst!\n";
                    return true;
                }
            }
        }
    }
    std::cout << "Not even a pair? Hopefully some better's in store!\n";
    return false;
}

void Hand::sortByValue() {
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i = 0; i < 5; i++) {
            if(i-1 >= 0 && cards[i].getValue() < cards[i-1].getValue()) {
                Card tempCard = cards[i];
                cards[i] = cards[i - 1];
                cards[i - 1] = tempCard;
                sorted = false;
            }
        }
    }
}