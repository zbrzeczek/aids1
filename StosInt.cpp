//
// Created by Zuza on 2024-03-19.
//

#include "StosInt.h"
#include <iostream>

StosInt::StosInt() : topHead(nullptr), bottom(nullptr) {}

StosInt::~StosInt(){
    while (!isEmpty()) {
        pop();
    }
}

int StosInt::isEmpty() const {
    return topHead == nullptr;
}

void StosInt::push(int value) {
    NodeInt *newNode = new NodeInt;
    newNode->value = value;
    newNode->next = topHead;
    topHead = newNode;
    if (bottom == nullptr) bottom = newNode;
}
void StosInt::pop() {
    NodeInt *temp = new NodeInt;
    temp = topHead;
    topHead = topHead->next;
    delete temp;
}

void StosInt::add(int add) {
    topHead->value = topHead->value + add;
}

void StosInt::display() {
    NodeInt *current = topHead; // Start from the bottom of the stack

    while (current != nullptr) {
        std::cout << current->value << " "; // Display the value
        current = current->next; // Move to the next node
    }
}

int StosInt::topValue() {
    return topHead->value;
}