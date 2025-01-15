#include <iostream>
#include <vector>

class Hand {
    std::vector<char> cards_left;
    std::vector<char> cards;
    int total;
    int counter;

    public:
    Hand(std::vector<char> deck, int num_cards);
    char get_card();
};

//to be continued