//
// Created by Zuza on 2024-03-19.
//

#ifndef AIDS1_STOSINT_H
#define AIDS1_STOSINT_H

#include "NodeInt.h"

class StosInt {
private:
    NodeInt *topHead;
public:
    StosInt();

    ~StosInt();

    int isEmpty() const;
    void push(int valueNowe);
    void pop();
    int topValue();
};


#endif //AIDS1_STOSINT_H
