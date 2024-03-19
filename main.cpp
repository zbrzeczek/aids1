
#include <iostream>
#include "StosString.h"
#include "List.h"

#define TRUE 1
#define FALSE 0


void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Don't forget to null-terminate the destination string
}

int my_strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    // Return the difference between the characters at the current positions
    return *(unsigned char*)str1 - *(unsigned char*)str2;
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
    int *ptrTablicaMaxMin = nullptr;
    int iloscMaxMin = 0;

    std::cin >> token;
    while (token != '.') {

        if(token == ' ') std::cin >> token;

        tokenInt = 0;

        //NodeString *zmienna = new NodeString;
        char *temp = new char[tokenInt + 2];

        char* string;
        while (token != ' ') {
            temp[tokenInt] = token;
            temp[tokenInt + 1] = '\0';

            string = new char[tokenInt + 2];
            my_strcpy(string, temp);

            tokenInt++;
            std::cin.get(token);
        }
        //std::cout << string;

        if (my_strcmp(string, "MAX") == FALSE || my_strcmp(string, "MIN") == FALSE || my_strcmp(string, "IF") == FALSE || my_strcmp(string, "N") == FALSE) {
            while (!stosZnakow.isEmpty() && my_strcmp(stosZnakow.topValue(), "*") == TRUE && my_strcmp(stosZnakow.topValue(), "/") == TRUE && my_strcmp(stosZnakow.topValue(), "+") == TRUE && my_strcmp(stosZnakow.topValue(), "-") == TRUE){
                lista.insert(stosZnakow.topValue());
                stosZnakow.pop();
            }
            stosZnakow.push(string);
        }
        else if (my_strcmp(string, "*") == FALSE || my_strcmp(string, "/") == FALSE) {
            while (my_strcmp(stosZnakow.topValue(), "+") == TRUE && my_strcmp(stosZnakow.topValue(), "-") == TRUE){
                lista.insert(stosZnakow.topValue());
                stosZnakow.pop();
            }
            stosZnakow.push(string);
        }
        else if (my_strcmp(string, "+") == FALSE || my_strcmp(string, "-") == FALSE) {
            while (!stosZnakow.isEmpty()){
                lista.insert(stosZnakow.topValue());
                stosZnakow.pop();
            }
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
            lista.insert(stosZnakow.topValue());
            stosZnakow.pop();
        }
        else if (my_strcmp(string, ",") == FALSE) {
            iloscMaxMin++;
            if (ptrTablicaMaxMin == nullptr){

            }
            else {
                ptrTablicaMaxMin = (int *)realloc(ptrTablicaMaxMin, iloscMaxMin * sizeof(int));

            }
        }
        else {
            lista.insert(string);
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

