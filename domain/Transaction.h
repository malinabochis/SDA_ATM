#ifndef SDA_CPP_TRANSACTION_H
#define SDA_CPP_TRANSACTION_H

struct PaymentBanknote {
    int value;
    int number;
};

class Transaction { // tranzactiile le pun intr-o multime later on...in lab 3
private:
    int id;
    int sum;
    PaymentBanknote* banknotes;  // tranzactia imi arata cat am pus, cat a iesit, cat a ramas
    int noBanknotes;

public:
    Transaction(); // default constructor

    // constructor
    Transaction(int id, int sum, PaymentBanknote* b, int noBanknotes);

    // copy constructor
    Transaction(const Transaction& source); // fiecare tranzacție are "banii" ei proprii, chiar dacă sumele sunt identice.

    // "=" operator
    Transaction& operator=(const Transaction& source);

    // "==" operator
    bool operator==(const Transaction& source) const; // equal if id is equal

    // getters
    [[nodiscard]] int getId() const;
    [[nodiscard]] int getSum() const;
    [[nodiscard]] PaymentBanknote* getBanknotes() const;
    [[nodiscard]] int getNoBanknotes() const;

    // destructor:
    ~Transaction();
};


#endif //SDA_CPP_TRANSACTION_H
