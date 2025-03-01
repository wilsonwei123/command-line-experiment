#include <cstdlib>
#include <ctime>
#include "blackjack.hpp"

std::vector<char> drawn_cards;
int split = 0;

Hand::Hand(std::vector<char> deck, int num_cards) {
    cards_left = deck;
    counter = num_cards;
}

void Hand::change_total(int diff) {
    total -= diff;
}

void Hand::add_card(char card) {
    cards.push_back(card);
    
    if (card == 'a') {
        total += 11;
    } else if (card == 'j' || card == 'q' || card == 'k' || card == 't') {
        total += 10;
    } else {
        total += card - '0';
    }
}

void Hand::sub_card(char card) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == card) {
            cards.erase(cards.begin() + i);
            break;
        }
    }
    
    if (card == 'a') {
        total -= 11;
    } else if (card == 'j' || card == 'q' || card == 'k' || card == 't') {
        total -= 10;
    } else {
        total -= card - '0';
    }
}

char Hand::deal_card() {
    int i = rand() % counter;
    cards.push_back(cards_left[i]);
    char dealt_card = cards[cards.size() - 1];
    cards_left.erase(cards_left.begin() + i);

    if (dealt_card == 'a') {
        total += 11;
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

int Hand::get_total() {
    return total;
}

int deal() {
    char response;
    int num_aces = 0, used_aces = 0;

    std::vector<char> stan_deck = {'a', 'a', 'a', 'a', '2', '2', '2', '2', '3', '3', '3', '3', '4', '4', '4', '4', '5', '5', '5', '5', '6', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '8', '9', '9', '9', '9', 't', 't', 't', 't', 'j', 'j', 'j', 'j', 'q', 'q', 'q', 'q', 'k', 'k', 'k', 'k'};
    Hand player_hand(stan_deck, 52);
    char first_card = player_hand.deal_card(), second_card = player_hand.deal_card();
    drawn_cards = {first_card, second_card};
    std::cout << "\nYour current hand: " << first_card << ", " << second_card << "\n" << "Your current total: " << player_hand.get_total() << "\n";
    if (player_hand.get_total() == 21) {
        std::cout << "\n\nBLACKJACK!!\n\n";
        return 21;
    }
    if (first_card == second_card) {
        std::cout << "\nWould you like to split? y for yes, type any other key to continue with no\n";
        std::cin >> response;
        
        if (response == 'y') {
            split = 1;
        }
    }
    
    if (split != 1) {
        std::cout << "\nEnter 1 to hit, 2 to stand, 3 to double down: ";
        std::cin >> response;
        if (response == '1') {
            drawn_cards.push_back(player_hand.deal_card());
        } else if (response == '2') {
            std::cout << "You stood with a total of " << player_hand.get_total() << "\n";
            return player_hand.get_total();
        } else if (response == '3') {
            drawn_cards.push_back(player_hand.deal_card());

            if (player_hand.get_total() > 21) {
                num_aces = 0;
                for (char card : drawn_cards) {
                    if (card == 'a') {
                        num_aces++;
                    }
                }
                
                while (player_hand.get_total() > 21 && num_aces > 0) {
                    num_aces--;
                    player_hand.change_total(10);
                }
            }

            if (player_hand.get_total() > 21) {
                std::cout << "\nYou doubled down, and bust!\n";
            } else if (player_hand.get_total() < 21) {
                std::cout << "\nYou doubled down with a total of " << player_hand.get_total() <<"\n";
            } else {
                std::cout << "\nYou doubled down with a total of 21!";
            }
            std::cout << "\nYour total: " << player_hand.get_total() << "\n";
            return player_hand.get_total();
        }
    }

    if (split != 1) {
        std::cout << "Your current hand: ";
        for (int i = 0; i < drawn_cards.size(); i++) {
            std::cout << drawn_cards[i] << " ";
        }
        std::cout << "\nYour current total: " << player_hand.get_total() << "\n";
    }

    if (split != 1) {
        while (player_hand.get_total() < 21) {
            std::cout << "\nEnter 1 to hit, 2 to stand: ";
            std::cin >> response;
            if (response == '1') {
                drawn_cards.push_back(player_hand.deal_card());
            } else if (response == '2') {
                std::cout << "You stood with a total of " << player_hand.get_total() << "\n";
                return player_hand.get_total();
            }
            if (player_hand.get_total() == 21) {
                std::cout << "\nYou hit 21!\n";
                return 21;
            }
            std::cout << "Your current hand: ";
            for (int i = 0; i < drawn_cards.size(); i++) {
                std::cout << drawn_cards[i] << " ";
            }

            num_aces = 0;
            for (char card : drawn_cards) {
                if (card == 'a') {
                    num_aces++;
                }
            }
            num_aces -= used_aces;

            if (player_hand.get_total() > 21 && num_aces > 0) {
                player_hand.change_total(10);
                used_aces++;
            }

            std::cout << "\nYour current total: " << player_hand.get_total() << "\n";

        }

        std::cout << "\nBust!\n";
        return player_hand.get_total();
    } else {
        Hand split_hand(player_hand.get_cards_left(), (player_hand.get_cards_left()).size());
        while (player_hand.get_total() < 21 || split_hand.get_total() < 21) {

        }
    }

    return player_hand.get_total();
}

int main() {
    srand(time(0));
    deal();
    return 0;
}
