//
// Created by Zuza on 2024-03-19.
//

#ifndef AIDS1_STOSINT_H
#define AIDS1_STOSINT_H

#include "NodeInt.h"

class StosInt {
private:
    NodeInt *topHead;
    NodeInt *bottom;
public:
    StosInt();

    ~StosInt();

    int isEmpty() const;
    void push(int value);
    void pop();
    void add(int add);
    void display();
    int topValue();
};


#endif //AIDS1_STOSINT_H
