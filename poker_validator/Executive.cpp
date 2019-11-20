#include "Executive.h"

Executive::Executive(std::string filename) {
    std::ifstream inFile;
    std::string cardVal;

    Card card[5];
    int i = 0, userInput;

    inFile.open(filename);
    if(inFile.is_open()) {
        /* InFile */
        while(inFile >> cardVal) {
            card[i] = parse(cardVal);
            i++;
        }
        hand = new Hand(card);
    } else {
        std::cout << "Error: file unfound, please try again.\n";
        throw;
    }

    do {
        menu();
        std::cout << "\nCheck your hand: ";
        std::cin >> userInput;
        handle(userInput);
    } while(userInput != 10);

    delete hand;
}

Card Executive::parse(std::string str) {
    if(str.length() == 3) {
        if((atoi)(&str.at(0)) != 10) {     // checks if the number is 10
            exit(-1);
        }
        if(isValidSuit(str.at(2))) {
            return(Card(10, getSuitVal(str.at(2))));
        }
    } else if (str.length() == 2) {
        if((str.at(0) == 'A' 
            || str.at(0) == 'J' 
            || str.at(0) == 'Q' 
            || str.at(0) == 'K')
            && isValidSuit(str.at(1))) {
                return(Card(getFaceVal(str.at(0)), getSuitVal(str.at(1))));
        } else if ((((atoi)(&str.at(0)) > 1) && ((atoi)(&str.at(0))) < 10) && isValidSuit(str.at(1))) {
            return (Card((atoi)(&str.at(0)), getSuitVal(str.at(1))));
        } else {
            std::cout << str + " is an invalid card.\n";
            exit(-1);
        }
    } else {
        std::cout << str + "is an invalid card.\n";
        exit(-1);
    }
    std::cout << "Error.\n";
    exit(-1);
}

bool Executive::isValidSuit(char s) {
    if (s == 'S' || s == 'C' || s == 'D' || s == 'H') {
        return true;
    }
    std::cout << "Invalid suit.\n";
    exit(-1);
}

Suit Executive::getSuitVal(char s) {
    if (s == 'S') {
        return Suit::SPADES;
    } else if(s == 'C') {
        return Suit::CLUBS;
    } else if(s == 'H') {
        return Suit::HEARTS;
    } else if(s == 'D') {
        return Suit::DIAMONDS;
    } else {
        throw "Invalid face card passed!\n";
    }
}

int Executive::getFaceVal(char s) {
    if(s == 'A') {
        return 1;
    } else if (s == 'J') {
        return 11;
    } else if (s == 'Q') {
        return 12;
    } else if (s == 'K') {
        return 13;
    } else {
        throw "Invalid face card passed!\n";
    }
}

void Executive::menu() {
    std::cout << " ======= OPTIONS ======= "
              << "\n\t1. Royal Flush"
              << "\n\t2. Straight Flush"
              << "\n\t3. Four of a Kind"
              << "\n\t4. Full House"
              << "\n\t5. Flush"
              << "\n\t6. Straight"
              << "\n\t7. Three of a Kind"
              << "\n\t8. Two Pair"
              << "\n\t9. Pair"
              << "\n\t10. Exit";
}

void Executive::handle(int input) {
    switch(input) {
        case 1:
            hand->isRoyalFlush();
            break;
        case 2:
            hand->isStraightFlush();
            break;
        case 3:
            hand->isFourOfAKind();
            break;
        case 4:
            hand->isFullHouse();
            break;
        case 5:
            hand->isFlush();
            break;
        case 6:
            hand->isStraight();
            break;
        case 7:
            hand->isThreeOfAKind();
            break;
        case 8:
            hand->isTwoPair();
            break;
        case 9:
            hand->isPair();
            break;
        default:
            break;
    }
}