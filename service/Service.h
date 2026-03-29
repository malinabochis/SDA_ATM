#ifndef SDA_CPP_SERVIE_H
#define SDA_CPP_SERVIE_H

#pragma once
#include "ATM.h"
#include "../repository/RepoTransactions.h"

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
};

#endif //SDA_CPP_SERVIE_H