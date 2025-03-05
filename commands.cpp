#include "commands.hpp"

using namespace std;

void casino() {
    run_casino();
}

void dumdum_calculator() {
    double a, b, result;
    string operation;
    cin >> a >> operation >> b;

    if (operation == "plus") {
        result = a + b;
    } else if (operation == "minus") {
        result = a - b;
    } else if (operation == "times") {
        result = a * b;
    } else if (operation == "divide") {
        result = a / b;
    }

    // make it include squares and square root

    cout << "Result: " << result << "\n\n";
}
