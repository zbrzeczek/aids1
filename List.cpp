//
// Created by Zuzanna Brzęczek on 15/03/2024.
//

#include <iostream>
#include <cstring>
#include "List.h"
#include "NodeString.h"

List::List() : head(nullptr){}
List::~List() {
    while (head != nullptr){
        del();
    }
}
void List::insert(char *value) {
    if (head != nullptr){
        NodeString* newNode = new NodeString;
        newNode->value = new char[strlen(value) + 1]; // +1 for the null terminator
        strcpy(newNode->value, value);
        newNode->next = nullptr;

        NodeString *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else{
        NodeString* newNode = new NodeString;
        newNode->value = new char[strlen(value) + 1];
        strcpy(newNode->value, value);
        newNode->next = nullptr;
        head = newNode;
    }
}

void List::disp() {
    NodeString *temp = head;
    while (temp != nullptr) {
        printf("%s ", temp->value);
        temp = temp->next;
    }
}

void List::del() {
    NodeString *temp = head;
    head = head->next; // Move head to the next node
    delete temp;
}

int List::isEmpty() {
    return head == nullptr;
}

char * List::getHeadValue() {
    if (head != nullptr) return head->value;
    else return nullptr;
}