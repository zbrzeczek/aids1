//
// Created by Zuza on 2024-04-04.
//

#ifndef AIDS1_STOS_H
#define AIDS1_STOS_H

#include "Node.h"

class Stos {
private:
    Node *topHead;
    Node *bottom;
public:
    Stos();

    ~Stos();

    int isEmpty() const;
    void push(int value);
    void push(char *value);
    void pop();
    void add(int add);
    void display();
    NodeItem* topValue();
};


#endif //AIDS1_STOS_H
