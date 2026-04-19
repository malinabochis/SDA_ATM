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
    std::cout << "4. Show transactions sorted by date\n";
    std::cout << "5. Show transactions sorted by sum\n";
    std::cout << "6. Show transactions sorted by number of banknotes\n";
    std::cout << "0. Exit\n";
}

void UI::printTransaction(const Transaction& t) {
    Date d = t.getDate();
    std::cout << "ID: " << t.getId()
              << " | Sum: " << t.getSum()
              << " | Banknotes: " << t.getNoBanknotes()
              << " | Date: " << d.day << "/" << d.month << "/" << d.year
              << "\n";
}

void UI::showTransactions(const OrderedSet<Transaction>& set) {
    if (set.noElems() == 0) {
        std::cout << "No transactions available.\n";
        return;
    }

    for (int i = 0; i < set.noElems(); i++) {
        printTransaction(set.getAt(i));
    }
}

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
                std::cout << "Enter banknote value: ";
                std::cin >> value;

                if (value <= 0) {
                    std::cout << "-> ERROR: Banknote value must be strictly positive!\n";
                    break;
                }

                std::cout << "Enter number of banknotes: ";
                std::cin >> number;

                if (number <= 0) {
                    std::cout << "-> ERROR: Invalid number of banknotes!\n";
                    break;
                }

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
                showTransactions(srv.getTransactionsSortedById());
                break;
            }
            case 4: {
                showTransactions(srv.getTransactionsSortedByDate());
                break;
            }
            case 5: {
                showTransactions(srv.getTransactionsSortedBySum());
                break;
            }
            case 6: {
                showTransactions(srv.getTransactionsSortedByNoBanknotes());
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