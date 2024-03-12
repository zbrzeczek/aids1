//
// Created by Zuzanna Brzęczek on 12/03/2024.
//

#ifndef AIDS1_STOSINT_H
#define AIDS1_STOSINT_H

struct NodeInt{
    NodeInt *next;
    int value;
};

class StosInt {
private:
    NodeInt *topHead;
public:
    StosInt();

    ~StosInt();

    int isEmpty() const;
    void push(int liczbaNowa);
    void pop();
    int topValue();
};


#endif //AIDS1_STOSINT_H
