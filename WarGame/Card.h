// This will be the header file for the Card Class

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Card {
    private:
        int suit;
        int rank;
    public:
        Card(int, int);
        int getSuit();
        int getRank();
        void setSuit(int);
        void setRank(int);
};
