//
// Created by Zuzanna Brzęczek on 15/03/2024.
//

#ifndef AIDS1_LIST_H
#define AIDS1_LIST_H

#include "NodeString.h"

class List {
private:
    NodeString *head;
public:
    List();
    ~List();

    void insert(char * value);
    void del();
    void disp ();
    int isEmpty();
    char *getHeadValue();
};


#endif //AIDS1_LIST_H
