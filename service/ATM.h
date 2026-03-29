#ifndef SDA_ATM_ATM_H
#define SDA_ATM_ATM_H

#pragma once
#include "../TAD/Collection.h" // cale relativa, .. scoate un nivel mai sus, apoi zic din acelasi nivel cu .., ce vreau

class ATM {
private:
    Collection<int> banknotes; // valorile bancnotelor (ex: 10,50,100)

public:
    ATM();
    void addBanknotes(int value, int number);
    int noAvailableBanknotes(int value) const;
    bool extractBanknotes(int value, int number);
};

#endif //SDA_ATM_ATM_H