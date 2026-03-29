#ifndef SDA_ATM_REPOTRANSACTIONS_H
#define SDA_ATM_REPOTRANSACTIONS_H

#include "../domain/Transaction.h"

class RepoTransactions {
private:
    Transaction* transaction; // vector dinamic
    int size;
    int capacity;

    void resize();

public:
    RepoTransactions();
    void add(const Transaction& t);
    int getSize() const;
    Transaction get(int index) const;
    ~RepoTransactions();
};

#endif