// this will be the class for Card characteristics
#include <iostream>
#include "Card.h"
#include <cstdlib>
#include <vector>

using namespace std;

//Card(suit, rank)
Card::Card(int x, int y) {
    suit = x;
    rank = y;
}

int Card::getSuit() {
    return suit;
}

int Card::getRank() {
    return rank;
}

void Card::setSuit(int x) {
    suit = x;
}

void Card::setRank(int x) {
    rank = x;
}
/*
// for testing purposes:
int main() {
    Card lucky(5, 6);
    cout << "Rank is: " << lucky.getRank() << endl;
    cout << "Suit is: " << lucky.getSuit() << endl;
    lucky.setSuit(10);
    lucky.setRank(2);
    cout << "Rank is now: " << lucky.getRank() << endl;
    cout << "Suit is now: " << lucky.getSuit() << endl;
    //cout << "blah is: " << lucky.rank << endl;
}
*/
