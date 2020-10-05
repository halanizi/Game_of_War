#include "Card.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

vector<Card> makeDeck();
vector<Card> shuffle(vector<Card>);
void play(vector<Card>, vector<Card>);
string suitToName(Card);
string rankToName(Card);

int main() {
    cout << "Welcome to the game of War" << endl;
    cout << "Press y to begin!" << endl;
    string y;
    cin >> y;
    if (y != "y") {
        main();
    } else {
        vector<Card> deck = makeDeck();
        deck = shuffle(deck);

        vector<Card> userDeck; // split deck in half
        for (unsigned i = 0; i < (deck.size()/2); i++) {
            userDeck.push_back(deck[i]);
        }
        vector<Card> computerDeck; // split deck in half
        for (unsigned j = (deck.size()/2); j < deck.size(); j++) {
            computerDeck.push_back(deck[j]);
        }
        // Game will keep going until someone looses all their cards:
        play(userDeck, computerDeck);
    }

    return 0;
}

string suitToName(Card val) {
    string suit;
    if (val.getSuit() == 1) {
        suit = "diamonds";
    } else if (val.getSuit() == 2) {
        suit = "clubs";
    } else if (val.getSuit() == 3) {
        suit = "hearts";
    } else if (val.getSuit() == 4) {
        suit = "spades";
    } else {
        suit = "?";
    }
    return suit;
}

string rankToName(Card val) {
    string rank;
    if (val.getRank() == 11) {
        rank = "Jack";
    } else if (val.getRank() == 12) {
        rank = "Queen";
    } else if (val.getRank() == 13) {
        rank = "King";
    } else if (val.getRank() == 14) {
        rank = "Ace";
    } else {
        rank = to_string(val.getRank());
    }
    return rank;
}

void play(vector<Card> userDeck, vector<Card> computerDeck) {

    label:
        cout << "User deck currently has: " << userDeck.size() << " cards" << endl;
        cout << "Computer deck currently has: " << computerDeck.size() << " cards" << endl;
        cout << endl << "Press y to start the round!" << endl;
        string y;
        cin >> y;
        if (y != "y") goto label;

    cout << "User has the: " << (rankToName(userDeck.front())) << " of " << (suitToName(userDeck.front())) << endl;
    cout << "Computer has the: " << (rankToName(computerDeck.front())) << " of " << (suitToName(computerDeck.front())) << endl;

    if ((userDeck.front()).getRank() > ((computerDeck.front()).getRank())) {
        cout << "user's card is ranked higher than computer!" << endl;
        Card lost = computerDeck.front(); // points to computer's card
        computerDeck.erase(computerDeck.begin()); // remove computer's card
        userDeck.push_back(lost); // put computer's card at the end of the user's

        Card won = userDeck.front(); // card won is put at the bottom of same user's deck who won
        userDeck.erase(userDeck.begin()); // remove the card from the top
        userDeck.push_back(won); // put card at bottom

        // update their decks (computer's card goes to bottom of user's deck)
    }
    else if ((userDeck.front()).getRank() < (computerDeck.front().getRank())) {
        cout << "Computer's chosen card is ranked higher than yours!" << endl;
        Card lost = userDeck.front();
        userDeck.erase(userDeck.begin());
        computerDeck.push_back(lost);

        Card won = computerDeck.front();
        computerDeck.erase(computerDeck.begin()); // remove the card from the top
        computerDeck.push_back(won); // put card at bottom

    }
    else {
        cout << "Comparing suits..." << endl;
        if ((userDeck.front()).getSuit() > (computerDeck.front().getSuit())) {
            cout << "User has bigger suit!" << endl;
            // user gets the card
            Card lost = computerDeck.front(); // points to computer's card
            computerDeck.erase(computerDeck.begin()); // remove computer's card
            userDeck.push_back(lost); // put computer's card at the end of the user's

            Card won = userDeck.front(); // card won is put at the bottom of same user's deck who won
            userDeck.erase(userDeck.begin()); // remove the card from the top
            userDeck.push_back(won); // put card at bottom


        }
        else if ((userDeck.front()).getSuit() < (computerDeck.front().getSuit())) {
            cout <<"Computer has bigger suit!" << endl;
            // computer gets the card
            Card lost = userDeck.front();
            userDeck.erase(userDeck.begin());
            computerDeck.push_back(lost);

        Card won = computerDeck.front(); // card won is put at the bottom of same user's deck who won
        computerDeck.erase(computerDeck.begin()); // remove the card from the top
        computerDeck.push_back(won); // put card at bottom


        } else {
            cout << "It's a tie!" << endl;
            Card frontUser = userDeck.front();
            Card frontComp = computerDeck.front();
            userDeck.erase(userDeck.begin());
            computerDeck.erase(computerDeck.begin());
            userDeck.push_back(frontUser);
            computerDeck.push_back(frontComp);
            // put both cards at the bottom of each's deck
        }

    }
    if (userDeck.size() > 0 && computerDeck.size() > 0) {
        play(userDeck, computerDeck);
    } else if (userDeck.size() == 0 && computerDeck.size() > 0) {
        cout << "You lost to the computer!" << endl;
    } else if (computerDeck.size() == 0 && userDeck.size() > 0) {
        cout << "Congrats you won!" << endl;
    } else cout <<"Uhh something went wrong. Ending" << endl;
}

vector<Card> makeDeck() {
    // diamond (lowest), club, heart, spades (highest)
    // 2 (lowest), 3, 4, 5, 6, 7, 8 ,9, 10, jack, queen, king, ace

    vector<Card> deck;
    // suit 1 = diamond
    for (int i = 2; i <15; i++) {
        deck.push_back(Card(1, i));
    }
    // suit 2 = club
    for (int i = 2; i <15; i++) {
        deck.push_back(Card(2, i));
    }
    // suit 3 = heart
    for (int i = 2; i < 15; i++) {
        deck.push_back(Card(3, i));
    }
    // suit 4 = spades
    for (int i = 2; i < 15; i++) {
        deck.push_back(Card(4, i));

    }
    return deck;
}

vector<Card> shuffle(vector<Card> deck) {
    random_shuffle(deck.begin(), deck.end());
    return deck;
}
