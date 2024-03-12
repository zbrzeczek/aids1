
#include <iostream>
#include "StosInt.h"
#include "StosString.h"

#define TRUE 1
#define FALSE 0

struct listNode {
    int value;
    listNode * next;
};

int my_strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    // Return the difference between the characters at the current positions
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}



void displayListString(listNode *head) {
    listNode *current = head;

    while (current->next != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;
}
void displayListInt(NodeInt *head) {
    NodeInt *current = head;

    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void conversionONP (){
    char token;
    int tokenInt;
    StosString stosZnakow;

    std::cin >> token;
    while (token != '.') {

        if(token == ' ') std::cin >> token;

        tokenInt = 0;

        NodeString *zmienna = new NodeString;
        char *temp = new char[tokenInt + 2];
        char *string = nullptr;

        listNode *head = nullptr;


        while (token != ' ') {
            temp[tokenInt] = token;
            temp[tokenInt + 1] = '\0';

            char* newString = new char[tokenInt + 2];
            strcpy(newString, temp);

            if (string != nullptr) delete[] string;
            string = newString;

            tokenInt++;
            std::cin.get(token);
        }

        if (my_strcmp(string, "MAX") == FALSE || my_strcmp(string, "MIN") == FALSE ||
        my_strcmp(string, "IF") == FALSE || my_strcmp(string, "n") == FALSE) {
            stosZnakow.push(string);
            std::cout << stosZnakow.topValue();
        }
        else if (my_strcmp(string, "*") == FALSE || my_strcmp(string, "/") == FALSE) {
            stosZnakow.push(string);
        }
        else if (my_strcmp(string, "(") == FALSE) {
            stosZnakow.push(string);
        }
        else if (my_strcmp(string, ")") == FALSE) {
            while (my_strcmp(stosZnakow.topValue(), "(") != FALSE) {
                std::cout << stosZnakow.topValue();
                stosZnakow.pop();
            }
            stosZnakow.pop();
        }
        else {
            listNode *tempor = new listNode;
            listNode *top = new listNode;
            int x;
            tempor->value = sscanf(string, "%d", &x);
            tempor->next = nullptr;
            top = head;
            while (top->next != nullptr) top = top->next;
            top->next = tempor;
        }

        delete []temp;
        delete []string;
        displayListString(head);
    }
    std::cout << "\n";
    //displayListString(head);
}
void calculationsONP (){

}


int main(int argc, const char * argv[]) {
    int iloscRownan;
    std::cin >> iloscRownan;

    NodeString *headery = new NodeString[iloscRownan];


    //aby najpierw wpisac wszystko pozniej liczyc 2 osobne petle
    //konversia
    for (int i = 0; i < iloscRownan ; i++){
        conversionONP(&headery[i]);
    }

    //kalkulacje + wyswietlanie
    for (int i = 0; i < iloscRownan ; i++){
        calculationsONP();
    }

    delete[] headery;
    return 0;
}

