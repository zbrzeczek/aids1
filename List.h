//
// Created by Zuzanna Brzęczek on 15/03/2024.
//

#ifndef AIDS1_LIST_H
#define AIDS1_LIST_H

#include "Node.h"

class List {
private:
    Node *head;
    Node *bottom;
public:
    List();
    ~List();

    void insert(int value);
    void insertChar(char * value);
    void del();
    void disp ();
    int isEmpty();
    Node *getHeadValue();
};


#endif //AIDS1_LIST_H
