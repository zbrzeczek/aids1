//
// Created by Zuza on 2024-03-19.
//

#include "StosInt.h"

StosInt::StosInt() : topHead(nullptr) {}

StosInt::~StosInt(){
    while (!isEmpty()) {
        pop();
    }
}

int StosInt::isEmpty() const {
    return topHead == nullptr;
}

void StosInt::push(int valueNowe) {
    NodeInt *newNode = new NodeInt;
    newNode->value = valueNowe;
    newNode->next = topHead;
    topHead = newNode;
}
void StosInt::pop() {
    NodeInt *temp = new NodeInt;
    temp = topHead;
    topHead = topHead->next;
    delete temp;
}
int StosInt::topValue() {
    return topHead->value;
}