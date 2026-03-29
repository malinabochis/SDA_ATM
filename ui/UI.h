#ifndef SEM3_BANCOMAT_UI_H
#define SEM3_BANCOMAT_UI_H


#pragma once
#include "../service/Service.h"

class UI {
private:
    Service srv;

    void menu() const;

public:
    UI();

    void run();
};

#endif //SEM3_BANCOMAT_UI_H
