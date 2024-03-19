//
// Created by Zuzanna Brzęczek on 12/03/2024.
//

#include "StosString.h"
#include "NodeString.h"
#include <iostream>
#include <cstring>


StosString::StosString() : topHead(nullptr) {}

StosString::~StosString() {
    while (!isEmpty()) {
        pop();
    }
}

int StosString::isEmpty() const {
    return topHead == nullptr;
}

void StosString::push(char *valueNowe) {
    NodeString *newNode = new NodeString;
    newNode->value = new char[strlen(valueNowe) + 1]; // +1 for the null terminator
    strcpy(newNode->value, valueNowe);
    newNode->next = topHead;
    topHead = newNode;
    //delete newNode;
}

void StosString::pop(){
    NodeString *temp = new NodeString;
    temp = topHead;
    topHead = topHead->next;
    delete temp;
}

char* StosString::topValue(){
    return topHead->value;
}