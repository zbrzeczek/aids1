//
// Created by Zuzanna Brzęczek on 15/03/2024.
//

#include <iostream>
#include "List.h"
#include "NodeString.h"

List::List(NodeString *head) : head(head){}
List::~List() {
    while (head != nullptr){
        del();
    }
}
void List::insert(char *value) {
    if (head->value != nullptr){
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
        head->value = new char[strlen(value) + 1];
        strcpy(head->value, value);
        head->next = nullptr;
    }
}

char *List::disp(int num) {
    NodeString *temp = head;
    for (int i = 0; i<num; i++){
        temp = temp->next;
    }
    return temp->value;
}

void List::del() {
    NodeString *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    delete temp;
}