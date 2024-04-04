//
// Created by Zuzanna Brzęczek on 15/03/2024.
//

#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"

#define TRUE 1
#define FALSE 0

List::List() : head(nullptr), bottom(nullptr){}
List::~List() {
    while (head != nullptr){
        del();
    }
}
void List::insert(int value) {
    //if (bottom != nullptr){
        Node* newNode = new Node;
        newNode->value.intValue = value; // +1 for the null terminator
        newNode->isInt= TRUE;
        newNode->next = nullptr;

        /*Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        head->next = newNode;*/
    if (head == nullptr) {
        head = bottom = newNode;
    } else {
        bottom->next = newNode;
        bottom = newNode;
    }
    //}
    //else{
    //}
}

void List::insertChar(char *value) {
    /*if (head != nullptr){
        Node* newNode = new Node;
        newNode->isInt= FALSE;
        newNode->value.stringValue = new char[strlen(value) + 1]; // +1 for the null terminator
        strcpy(newNode->value.stringValue, value);
        newNode->next = nullptr;

        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    //}*/
    //else{
        Node* newNode = new Node;
        newNode->isInt= FALSE;
    newNode->value.stringValue = new char[strlen(value) + 1];
    strcpy(newNode->value.stringValue, value);
        newNode->next = nullptr;
    if (head == nullptr) {
        head = bottom = newNode;
    } else {
        bottom->next = newNode;
        bottom = newNode;
    }
    //}
}

void List::disp() {
    Node *temp = head;
    while (temp != nullptr) {
        if (!temp->isInt) printf("%s ", temp->value.stringValue);
        else printf("%d ", temp->value.intValue);
        temp = temp->next;
    }
}

void List::del() {
    if (head != nullptr) {
        Node *temp = head;
        head = head->next; // Move head to the next node
        if (!temp->isInt) {
            delete[] temp->value.stringValue; // Deallocate memory for string value
        }
        delete temp; // Deallocate memory for node
    }
}

int List::isEmpty() {
    return head == nullptr;
}

Node* List::getHeadValue() {
    return head;
}