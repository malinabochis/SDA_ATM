#include "Transaction.h"


// default constructor
Transaction::Transaction() {
    id = -1;
    sum = 0;
    banknotes = nullptr;
    noBanknotes = 0;
    date = {1, 1, 1970};
}


// constructor

Transaction::Transaction(int id, int sum, PaymentBanknote* b, int noBanknotes, Date date) {
    this->id = id;
    this->sum = sum;
    this->noBanknotes = noBanknotes;
    this->date = date;

    banknotes = new PaymentBanknote[noBanknotes];
    for (int i = 0; i < noBanknotes; i++)
        banknotes[i] = b[i];
}


// copy constructor

Transaction::Transaction(const Transaction &source) {
    id = source.id;
    sum = source.sum;
    noBanknotes = source.noBanknotes;
    date = source.date;

    banknotes = new PaymentBanknote[noBanknotes];
    for (int i = 0; i < noBanknotes; i++)
        banknotes[i] = source.banknotes[i];
}


// "=" operator

Transaction &Transaction::operator=(const Transaction &source) {
    if (this == &source)
        return *this;

    delete[] banknotes; // cand faci o atribuire catre o variabila, intai stergi legatura ei cu adresa spre care pointuia inainte

    id = source.id;
    sum = source.sum;
    noBanknotes = source.noBanknotes;
    date = source.date;

    banknotes = new PaymentBanknote[noBanknotes];
    for (int i = 0; i < noBanknotes; i++)
        banknotes[i] = source.banknotes[i];

    return *this;
}


// "==" operator

bool Transaction::operator==(const Transaction &source) const {
    return id == source.id;
}

// getters
int Transaction::getId() const {
    return id;
}

int Transaction::getSum() const {
    return sum;
}

PaymentBanknote *Transaction::getBanknotes() const {
    return banknotes;
}

int Transaction::getNoBanknotes() const {
    return noBanknotes;
}

Date Transaction::getDate() const {
    return date;
}

// destructor:
Transaction::~Transaction() {
    delete[] banknotes;
}