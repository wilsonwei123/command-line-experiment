#include <cstdlib>
#include <ctime>
#include "blackjack.hpp"

int split = 0;

Hand::Hand (std::vector<char> deck, int num_cards) {
    cards_left = deck;
    counter = num_cards;
}

char Hand::deal_card() {
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
    
    return dealt_card;
}

std::vector<char> Hand::get_cards_left() {
    return cards_left;
}

int deal() {
    char response;

    std::vector<char> stan_deck = {'a', 'a', 'a', 'a', '2', '2', '2', '2', '3', '3', '3', '3', '4', '4', '4', '4', '5', '5', '5', '5', '6', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '8', '9', '9', '9', '9', 't', 't', 't', 't', 'j', 'j', 'j', 'j', 'q', 'q', 'q', 'q', 'k', 'k', 'k', 'k'};
    Hand player_hand(stan_deck, 52);
    char first_card = player_hand.deal_card(), second_card = player_hand.deal_card();
    std::cout << "\nYour current hand: " << first_card << ", " << second_card << "\n";
    if (first_card == second_card) {
        std::cout << "\nWould you like to split? y for yes, type any other key to continue with no\n";
        std::cin >> response;
        
        if (response == 'y') {
            split = 1;
            Hand split_hand(player_hand.get_cards_left(), 50);
        }
        //continue function later
    }
    return 0;
}

int main() {
    srand(time(0));
    deal();
    return 0;
}

