#ifndef SEM3_BANCOMAT_UI_H
#define SEM3_BANCOMAT_UI_H


#pragma once
#include "../service/Service.h"

class UI {
private:
    Service srv;
    void menu() const;
    static void printTransaction(const Transaction& t);
    static void showTransactions(const OrderedSet<Transaction>& set) ;

public:
    UI();
    void run();
};

#endif //SEM3_BANCOMAT_UI_H
