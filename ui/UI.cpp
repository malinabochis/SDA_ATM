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
// run
void UI::run() {
    int option = -1;

    while (option != 0) {
        menu(); // Show options
        std::cout << "Choose an option: ";
        std::cin >> option; // Citim de la tastatura

        switch (option) {
            case 1: {
                int value, number;
                std::cout << "Enter banknote value (e.g., 10, 20, 50, 100, 200, 500, 1000): ";
                std::cin >> value;
                if (int(value) != 10 && int(value) != 20 && int(value) != 50 && int(value) != 100 && int(value) != 200 && int(value) != 500 && int(value) != 1000) {
                    std::cout << "This type of banknote does not exist.";
                    break;
                }
                std::cout << "Enter number of banknotes: ";
                std::cin >> number;

                srv.addBanknotes(value, number);
                std::cout << "-> Banknotes successfully added to the ATM!\n";
                break;
            }
            case 2: {
                int sum;
                std::cout << "Enter the sum you want to extract: ";
                std::cin >> sum;

                try {
                    Transaction t = srv.extraction(sum);
                    std::cout << "-> Success! Transaction #" << t.getId() << " completed.\n";
                }
                catch (const std::exception& e) {
                    // Backtracking failed
                    std::cout << "-> ERROR: Insufficient funds or impossible banknote combination for this sum!\n";
                }
                break;
            }
            case 3: {
                srv.showTransaction();
                break;
            }
            case 0: {
                std::cout << "Shutting down ATM... Have a great day!\n";
                break;
            }
            default: {
                std::cout << "-> Invalid option! Please try again.\n";
                break;
            }
        }
    }
}