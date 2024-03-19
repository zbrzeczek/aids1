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
    List(NodeString *head);
    ~List();

    void insert(char * value);
    void del();
    char * disp (int num);
};


#endif //AIDS1_LIST_H
