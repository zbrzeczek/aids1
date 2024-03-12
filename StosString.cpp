//
// Created by Zuzanna Brzęczek on 12/03/2024.
//

#include "StosString.h"
#include <iostream>

/*void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Don't forget to null-terminate the destination string
}*/


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
    newNode->value = valueNowe;
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