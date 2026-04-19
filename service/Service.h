#ifndef SDA_CPP_SERVIE_H
#define SDA_CPP_SERVIE_H

#pragma once
#include "ATM.h"
#include "../repository/RepoTransactions.h"
#include "../TAD/OrderedSet.h"

class Service {
private:
    RepoTransactions repo;
    ATM atm;
    int nextId;
    bool backtrackExtraction(int rest, int stepIndex, int* currentPlan, int* finalPlan, const int* values);

public:
    Service();
    void addBanknotes(int value, int number);
    Transaction extraction(int sum);
    void showTransaction() const;
    [[nodiscard]] OrderedSet<Transaction> getTransactionsSortedBySum() const;
    [[nodiscard]] OrderedSet<Transaction> getTransactionsSortedById() const;
};

#endif //SDA_CPP_SERVIE_H