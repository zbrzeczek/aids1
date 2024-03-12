//
// Created by Zuzanna Brzęczek on 12/03/2024.
//

#ifndef AIDS1_STOSSTRING_H
#define AIDS1_STOSSTRING_H

struct NodeString {
    NodeString *next;
    char *value;
};

class StosString {
private:
    NodeString *topHead;
public:
    StosString();

    ~StosString();

    int isEmpty() const;
    void push(char *valueNowe);
    void pop();
    char *topValue();
};


#endif //AIDS1_STOSSTRING_H
