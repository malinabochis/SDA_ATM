#include "ATM.h"

// constructor

ATM::ATM() {
    // implicitly null
}


// add banknotes

void ATM::addBanknotes(int value, int number) {
    for (int i = 0; i < number; i++)
        banknotes.add(value); //banknotes e colectia de bancnote, daca pui mouse ul pe el iti arata de ce tip e bancnota (colectie)
}


// how many banknotes of a specific type do we have

int ATM::noAvailableBanknotes(int value) const {
    return banknotes.noOccurrences(value);
}


// extract banknotes (used in transactions)

bool ATM::extractBanknotes(int value, int number) {
    for (int i = 0; i < number; i++) {
        if (!banknotes.remove(value))
            return false;
    }
    return true;
}
