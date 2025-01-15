#include <iostream>
#include <vector>

class Hand {
    std::vector<char> cards_left;
    std::vector<char> cards;
    int total;
    int counter;

    public:
    Hand(std::vector<char> deck, int num_cards);
    char deal_card();
    std::vector<char> get_cards_left();
};

//to be continued