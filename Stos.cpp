//
// Created by Zuza on 2024-04-04.
//

#include "Stos.h"

#include <iostream>
#include <cstring>

#define TRUE 1
#define FALSE 0

Stos::Stos() : topHead(nullptr), bottom(nullptr) {}

Stos::~Stos(){
    while (!isEmpty()) {
        pop();
    }
}

int Stos::isEmpty() const {
    return topHead == nullptr;
}

void Stos::push(int value) {
    Node *newNode = new Node;
    newNode->value.intValue = value;
    newNode->isInt = TRUE;
    newNode->next = topHead;
    topHead = newNode;
    if (bottom == nullptr) bottom = newNode;
}

void Stos::push(char *valueNowe) {
    Node *newNode = new Node;
    newNode->value.stringValue = new char[strlen(valueNowe) + 1];
    newNode->isInt = FALSE;
    strcpy(newNode->value.stringValue, valueNowe);
    newNode->next = topHead;
    topHead = newNode;
    //delete newNode;
}

void Stos::pop() {
    Node *temp = topHead;
    topHead = topHead->next;
    delete temp;
}

void Stos::add(int add) {
    topHead->value.intValue = topHead->value.intValue + add;
}

void Stos::display() {
    Node *current = topHead; // Start from the bottom of the stack

    while (current != nullptr) {
        if(current->isInt) printf("%d ", current->value.intValue);
        else printf("%s ", current->value.stringValue);
        current = current->next; // Move to the next node
    }
}

NodeItem* Stos::topValue() {
    return &topHead->value;
}