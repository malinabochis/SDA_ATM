#include "Service.h"

#include <iostream>
#include <ctime>

static bool compDescBanknotes(const int& a, const int& b) {
    return a > b;
}

// constructor

Service::Service() : knownBanknotes(compDescBanknotes) {
    nextId = 1;
}

// add banknotes in ATM

void Service::addBanknotes(int value, int number) {
    atm.addBanknotes(value, number);
    knownBanknotes.add(value);
}



// helper extraction function

bool Service::backtrackExtraction(int rest, int stepIndex, int *currentPlan, int *finalPlan, const OrderedSet<int>& values) {
    int N = values.noElems(); // Câte tipuri unice avem?

    if (rest == 0) {
        for (int i = 0; i < N; i++)
            finalPlan[i] = currentPlan[i];
        return true;
    }

    if (stepIndex >= N || rest < 0) return false;  // am terminat tipurile de bancnote sau am scazut prea mult

    int val = values.getAt(stepIndex);
    int available = atm.noAvailableBanknotes(val);
    int maxPossible = std::min(rest / val, available);

    for (int take = maxPossible; take >= 0; take--) {
        currentPlan[stepIndex] = take;
        bool succes = backtrackExtraction(rest - (take * val), stepIndex + 1, currentPlan, finalPlan, values);
        if (succes) return true;
        // else se pune inapoi bancnota si se incearca alta configuratie
    }

    return false;
}


// extraction (transaction)

static Date getCurrentDate() {
    const time_t now = time(nullptr);
    const tm* local = localtime(&now);

    Date d{};
    d.day = local->tm_mday;
    d.month = local->tm_mon + 1; //months indexed from 0
    d.year = local->tm_year + 1900; //years are counted from 1900

    return d;
}

Transaction Service::extraction(int sum) {
    if (sum <= 0) throw std::exception();

    int N = knownBanknotes.noElems(); // Cate tipuri cunoaste bancomatul
    if (N == 0) throw std::exception(); // Daca nu s-a introdus niciun ban inca

    // Alocam planurile dinamic in functie de cate tipuri de bancnote avem
    int* currentPlan = new int[N](); // () de la final initializeaza array-ul cu 0 automat
    int* finalPlan = new int[N]();

    bool isPossible = backtrackExtraction(sum, 0, currentPlan, finalPlan, knownBanknotes);

    if (isPossible) {
        Date date = getCurrentDate();

        int uniqueBanknotes = 0;
        for (int i = 0; i < N; i++) {
            if (finalPlan[i] > 0) {
                atm.extractBanknotes(knownBanknotes.getAt(i), finalPlan[i]);
                uniqueBanknotes++;
            }
        }

        auto* extracted = new PaymentBanknote[uniqueBanknotes];
        int index = 0;
        for (int i = 0; i < N; i++) {
            if (finalPlan[i] > 0) {
                extracted[index].value = knownBanknotes.getAt(i);
                extracted[index].number = finalPlan[i];
                ++index;
            }
        }

        Transaction t(nextId++, sum, extracted, uniqueBanknotes, date);
        repo.add(t);

        delete[] extracted;
        delete[] currentPlan;
        delete[] finalPlan;

        return t;
    } else {
        delete[] currentPlan;
        delete[] finalPlan;
        throw std::exception();
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


static bool compByNoBanknotes(const Transaction& t1, const Transaction& t2) {
    return t1.getNoBanknotes() < t2.getNoBanknotes();
}

OrderedSet<Transaction> Service::getTransactionsSortedByNoBanknotes() const {
    OrderedSet<Transaction> sortedTransactions(compByNoBanknotes);
    int size = repo.getSize();
    for (int i = 0; i < size; i++)
        sortedTransactions.add(repo.get_transaction(i));
    return sortedTransactions;
}


static bool compByDate(const Transaction& t1, const Transaction& t2) {
    if (t1.getDate().year != t2.getDate().year)
        return t1.getDate().year < t2.getDate().year;
    if (t1.getDate().month != t2.getDate().month)
        return t1.getDate().month < t2.getDate().month;
    if (t1.getDate().day != t2.getDate().day)
        return t1.getDate().day < t2.getDate().day;
    return t1.getId() < t2.getId();
}

OrderedSet<Transaction> Service::getTransactionsSortedByDate() const {
    OrderedSet<Transaction> sortedTransactions(compByDate);
    int size = repo.getSize();
    for (int i = 0; i < size; i++)
        sortedTransactions.add(repo.get_transaction(i));
    return sortedTransactions;
}