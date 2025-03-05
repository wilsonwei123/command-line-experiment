#include "commands.hpp"

using namespace std;

void help_manual() {
    char response;
    cout << "Enter 1 for calculator help, 2 for casino help, 3 for cipher help, 4 for exit help: ";
    cin >> response;

    switch (response) {
        case '1':
            cout << "First, enter the word calc followed by a space and your first number. Then, enter your operation SPELT IN ENGLISH (plus, minus, times, divide) then your other number.\n\n";
            break;
        case '2':
            cout << "Enter the word casino and press number keys when required\n\n";
            break;
        case '3':
            cout << "To be added\n\n";
            break;
        case '4':
            cout << "Simply enter the word exit when not in another application\n\n";
            break;
        default:
            cout << "Invalid input\n\n"; 
            break;
    }
}

int main() {
    bool exit_status = false;
    string command;
    cout << "Enter help for info\n";
    
    cin >> command;

    while (command != "exit") {
        if (command == "help") {
            help_manual();
        } else if (command == "calc") {
            dumdum_calculator();
        } else if (command == "casino") {
            casino();
        } else if (command == "cipher") {
            //cipher to be added
        } else {
            cout << "Sorry, your input could not be detected. Please enter help for info\n\n";
        }
        
        cin >> command;
    }
}
