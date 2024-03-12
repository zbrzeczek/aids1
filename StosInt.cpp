//
// Created by Zuzanna Brzęczek on 12/03/2024.
//

#include "StosInt.h"
#include <iostream>

StosInt::StosInt() : topHead(nullptr) {}

StosInt::~StosInt() {
    while (!isEmpty()) {
        pop();
    }
}

int StosInt::isEmpty() const {
    return topHead == nullptr;
}
void StosInt::push(int liczbaNowa) {
    NodeInt *newNode = new NodeInt;
    newNode->value = liczbaNowa;
    newNode->next = topHead;
    topHead = newNode;
}
void StosInt::pop(){
    NodeInt *zmienna = topHead;
    topHead = topHead->next;
    delete zmienna;
}
int StosInt::topValue(){
    return topHead->value;
}