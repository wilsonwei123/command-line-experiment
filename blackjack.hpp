#include <iostream>
#include <vector>

class Hand {
    private:
        std::vector<char> &cards_left;
        int total, counter;

    public:
        std::vector<char> cards;

        Hand(std::vector<char> &deck, int num_cards);
        char deal_card();
        std::vector<char> get_cards_left();
        int get_total();
        void change_total(int diff);
        //void set_deck(std::vector<char> deck);
        void add_card(char card);
        void sub_card(char card);
};

//to be continued