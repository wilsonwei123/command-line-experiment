#include <iostream>
#include <vector>

class Hand {
    std::vector<char> cards_left;
    std::vector<char> cards;
    int total;
    int counter;

    public:
    void get_card();
};

//to be continued