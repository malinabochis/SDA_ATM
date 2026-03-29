#include "UI.h"
#include <iostream>

// constructor

UI::UI() {}

// menu
void UI::menu() const {
    std::cout << "\n-----------ATM--------\n";
    std::cout << "1. Add banknotes\n";
    std::cout << "2. Extract sum\n";
    std::cout << "3. Show transactions\n";
    std::cout << "0. Exit\n";
}

// run => in fct de ce alege utilizatorul, apeleaza aia aia aia
void UI::run() {


}