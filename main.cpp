
#include <iostream>
#include <cstring>
#include "StosString.h"
#include "StosInt.h"
#include "List.h"

#define TRUE 1
#define FALSE 0


int priority (const char* string){
    if (strcmp(string, "(") == FALSE || strcmp(string, ")") == FALSE){
        return -1;
    }
    else if (strcmp(string, "MAX") == FALSE || strcmp(string, "MIN") == FALSE || strcmp(string, "IF") == FALSE || strcmp(string, "N") == FALSE){
        return 2;
    }
    else if (strcmp(string, "*") == FALSE || strcmp(string, "/") == FALSE) {
        return 1;
    }
    else return 0;
}

void displayListString(NodeString *head) {
    NodeString *current = head;

    while (current != nullptr && current->value != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

void conversionONP (NodeString *head){
    char token;
    int tokenInt;
    StosString stosZnakow;
    List lista(head);

    StosInt stosIloscMinMax;

    std::cin >> token;
    while (token != '.') {

        if(token == ' ') std::cin >> token;
        if(token == '.') break;

        tokenInt = 0;

        //NodeString *zmienna = new NodeString;
        char *temp = new char[tokenInt + 2];

        char* string;
        while (token != ' ') {
            temp[tokenInt] = token;
            temp[tokenInt + 1] = '\0';

            string = new char[tokenInt + 2];
            strcpy(string, temp);

            tokenInt++;
            std::cin.get(token);
        }
        //std::cout << string;

        if (isdigit(string[0])){
            lista.insert(string);
        }
        else if (strcmp(string, "(") == FALSE) {
            stosZnakow.push(string);
        }
        else if (strcmp(string, ")") == FALSE) {
            while (strcmp(stosZnakow.topValue(), "(") != FALSE) {
                lista.insert(stosZnakow.topValue());
                stosZnakow.pop();
            }
            stosZnakow.pop();
        }
        else if (strcmp(string, ",") == FALSE){
            while (strcmp(stosZnakow.topValue(), "(") != FALSE) {
                lista.insert(stosZnakow.topValue());
                stosZnakow.pop();
            }
        }
        else {
            if (stosZnakow.isEmpty()) stosZnakow.push(string);
            else {
                while (priority(stosZnakow.topValue()) >= priority(string)) {
                    lista.insert(stosZnakow.topValue());
                    stosZnakow.pop();
                    if (stosZnakow.isEmpty()) break;
                }
                stosZnakow.push(string);
            }
        }

        delete []temp;
        delete []string;
    }
    while (!stosZnakow.isEmpty()){
        lista.insert(stosZnakow.topValue());
        stosZnakow.pop();
    }
    displayListString(head);
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
        headery[i].value = nullptr;
        headery[i].next = nullptr;
        conversionONP(&headery[i]);
    }

    //kalkulacje + wyswietlanie
    for (int i = 0; i < iloscRownan ; i++){
        calculationsONP();
    }

    //delete[] headery;
    return 0;
}

