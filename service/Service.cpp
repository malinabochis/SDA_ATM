#include "Service.h"

#include <iostream>

// constructor

Service::Service() {
    nextId = 1; // first transaction of the day
}


// add banknotes in ATM

void Service::addBanknotes(int value, int number) {
    atm.addBanknotes(value, number);
}


// helper extraction function

bool Service::backtrackExtraction(int rest, int stepIndex, int *currentPlan, int *finalPlan, const int *values) {
    if (rest == 0) {
        for (int i = 0; i < 7; i++)
            finalPlan[i] = currentPlan[i];
        return true;
    }
    if (stepIndex >= 7 || rest < 0) // am terminat tipurile de bancnote sau am scazut prea mult
        return false;

    int val = values[stepIndex];
    int available = atm.noAvailableBanknotes(val);
    int maxPossible = std::min(rest / val, available);

    if (val == 50 && maxPossible > 4)
        maxPossible = 4;

    for (int take = maxPossible; take >= 0; take--) {
        currentPlan[stepIndex] = take;
        bool succes = backtrackExtraction(rest - (take * val), stepIndex + 1, currentPlan, finalPlan, values);
        if (succes) return true;
        // else se pune inapoi bancnota si se incearca alta configuratie
    }

    return false; // nicio incercare nu a mers
}


// extraction (transaction)

Transaction Service::extraction(int sum) {
    if (sum <= 0) throw std::exception();

    int possibleValues[] = {1000, 500, 200, 100, 50, 20, 10};
    int currentPlan[7] = {0};
    int finalPlan[7] = {0};

    bool isPossible = backtrackExtraction(sum, 0, currentPlan, finalPlan, possibleValues);
    if (isPossible) {
        int uniqueBanknotes = 0;
        for (int i = 0; i < 7; i++)
            if (finalPlan[i] > 0) {
                atm.extractBanknotes(possibleValues[i], finalPlan[i]);
                uniqueBanknotes++;
            }

        PaymentBanknote* extracted = new PaymentBanknote[uniqueBanknotes];
        int index = 0;
        for (int i = 0; i < 7; i++)
            if (finalPlan[i] > 0) {
                extracted[index].value = possibleValues[i];
                extracted[index].number = finalPlan[i];
                ++index;
            }
        Transaction t(nextId++, sum, extracted, uniqueBanknotes);
        repo.add(t);
        delete[] extracted;
        return t;
    }
    else {
        throw std::exception();
    }
}

// show transactions

void Service::showTransaction() const {
    int size = repo.getSize();

    if (size == 0) {
        std::cout << "No registered transaction yet.\n";
        return;
    }

    std::cout << "\n=== ATM TRANSACTIONS HISTORY ===\n";

    for (int i = 0; i < size; i++) {
        const Transaction& t = repo.get_transaction(i);

        std::cout << "Transaction #" << t.getId() << " | Extracted Sum: " << t.getSum() << " RON\n";
        std::cout << "Used banknotes:\n";

        PaymentBanknote* banknotes = t.getBanknotes();
        int noBanknotes = t.getNoBanknotes();

        for (int j = 0; j < noBanknotes; j++) {
            std::cout << "  -> " << banknotes[j].number << " buc. x " << banknotes[j].value << " RON\n";
        }
        std::cout << "-----------------------------------\n";
    }
}


static bool compBySum(const Transaction& t1, const Transaction& t2) {
    return t1.getSum() < t2.getSum();
}

OrderedSet<Transaction> Service::getTransactionsSortedBySum() const {
    OrderedSet<Transaction> sortedTransactions(compBySum); //null set
    int size = repo.getSize();
    for (int i=0; i < size; i++)
        sortedTransactions.add(repo.get_transaction(i));
    return sortedTransactions;
}


static bool compById(const Transaction& t1, const Transaction& t2) {
    return t1.getId() < t2.getId();
}

OrderedSet<Transaction> Service::getTransactionsSortedById() const {
    OrderedSet<Transaction> sortedTransactions(compById);
    int size = repo.getSize();
    for (int i = 0; i < size; i++)
        sortedTransactions.add(repo.get_transaction(i));
    return sortedTransactions;
}