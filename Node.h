//
// Created by Zuza on 2024-04-04.
//

#ifndef AIDS1_NODE_H
#define AIDS1_NODE_H

union NodeItem {
    int intValue;
    char* stringValue;
};

struct Node{
    Node *next;
    NodeItem value;
    int isInt;
};

#endif //AIDS1_NODE_H
