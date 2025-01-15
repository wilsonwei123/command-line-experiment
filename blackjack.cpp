#include "blackjack.hpp"

void Hand::get_card() {
    int i = rand() % counter;
    cards.push_back(cards_left[i]);
    char dealt_card = cards[cards.size() - 1];
    cards_left.erase(cards_left.begin() + i);

    if (dealt_card == 'a') {
        total += 11;
        if (total > 21) {
            total -= 10;
        }
    } else if (dealt_card == 'j' || dealt_card == 'q' || dealt_card == 'k' || dealt_card == 't') {
        total += 10;
    } else {
        total += dealt_card - '0';
    }
}

//to be continued