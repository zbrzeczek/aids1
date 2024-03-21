
#include <iostream>
#include <cstring>
#include "StosString.h"
#include "StosInt.h"
#include "List.h"

#define TRUE 1
#define FALSE 0

char * intToString(int num) {
    int numDigits = 0;
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        numDigits++;
    }
    // Allocate memory for the character array
    char* result = new char[numDigits + 1]; // +1 for the null terminator

    // Convert the integer to characters
    int index = numDigits - 1;
    while (num != 0) {
        result[index--] = '0' + (num % 10); // Convert digit to character
        num /= 10;
    }
    result[numDigits] = '\0'; // Null terminator

    return result;
}

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

void znakDoListy(StosString *stosZnakow, StosInt *stosMaxMin, List *lista) {
    if (strcmp(stosZnakow->topValue(), "MIN") == FALSE || strcmp(stosZnakow->topValue(), "MAX") == FALSE){
        char *zmienna = stosZnakow->topValue();
        char *liczbaMinMax = intToString(stosMaxMin->topValue());

        char *newValue = new char[strlen(stosZnakow->topValue()) + strlen(liczbaMinMax) + 1];
        strcpy(newValue, zmienna);
        strcat(newValue, liczbaMinMax);

        newValue[strlen(stosZnakow->topValue()) +1 ] = '\0';

        lista->insert(newValue);
        stosMaxMin->pop();
        if (!stosMaxMin->isEmpty()) stosMaxMin->add(1);
    }
    else {
        lista->insert(stosZnakow->topValue());
    }
    stosZnakow->pop();
}

void calculationsOperator(char *token, StosInt *stos) {

}

int stringToInt (char *string) {

}

void conversionONP (List *lista){
    char token;
    int tokenInt;
    StosString stosZnakow;
    StosInt stosMaxMin;
    //List lista(head);

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

        if (isdigit(string[0])){
            lista->insert(string);
        }
        else if (strcmp(string, "(") == FALSE) {
            stosZnakow.push(string);
        }
        else if (strcmp(string, ")") == FALSE) {
            while (strcmp(stosZnakow.topValue(), "(") != FALSE) {
                znakDoListy(&stosZnakow, &stosMaxMin, lista);
                /*lista->insert(stosZnakow.topValue());
                stosZnakow.pop();*/
            }
            stosZnakow.pop();
        }
        else if (strcmp(string, ",") == FALSE){
            stosMaxMin.add(1);
            //do przypadkow gdy w min/max/if jest jakies rownanie w srodku ex. min( 1 , 2 * 5 + 6 , 2 ) .
            while (strcmp(stosZnakow.topValue(), "(") != FALSE){
                znakDoListy(&stosZnakow, &stosMaxMin, lista);
                /*lista->insert(stosZnakow.topValue());
                stosZnakow.pop();*/
            }
        }
        else {
            //ogarnienie liczby przy max min
            if (strcmp(string, "MIN") == FALSE || strcmp(string, "MAX") == FALSE) stosMaxMin.push(1);
            else if (strcmp(string, "IF") == FALSE) stosMaxMin.add(-2);


            if (stosZnakow.isEmpty()) stosZnakow.push(string);
            else {
                while (priority(stosZnakow.topValue()) >= priority(string)){
                    znakDoListy(&stosZnakow, &stosMaxMin, lista);
                    /*if (strcmp(stosZnakow.topValue(), "MIN") == FALSE || strcmp(stosZnakow.topValue(), "MAX") == FALSE){
                        char *zmienna = stosZnakow.topValue();
                        char *liczbaMinMax = intToString(stosMaxMin.topValue());

                        char *newValue = new char[strlen(stosZnakow.topValue()) + strlen(liczbaMinMax) + 1];
                        strcpy(newValue, zmienna);
                        strcat(newValue, liczbaMinMax);

                        newValue[strlen(stosZnakow.topValue()) +1 ] = '\0';

                        lista->insert(newValue);
                        stosMaxMin.pop();
                        if (!stosMaxMin.isEmpty())stosMaxMin.add(1);
                    }
                    else {
                        lista->insert(stosZnakow.topValue());
                    }
                    stosZnakow.pop();*/
                    if (stosZnakow.isEmpty()) break;
                }
                stosZnakow.push(string);
            }
        }

        delete []temp;
        delete []string;
    }
    while (!stosZnakow.isEmpty()){
        znakDoListy(&stosZnakow, &stosMaxMin, lista);
        //lista->insert(stosZnakow.topValue());
        //1stosZnakow.pop();
    }
    lista->disp();
}
void calculationsONP (List *lista){
    char *token;
    StosInt stosint;

    if (!lista->isEmpty()) token = lista->getHeadValue();
    while(!lista->isEmpty()) {
        if (isdigit(token[0])) {
            stosint.push(stringToInt(token));
        }
        else calculationsOperator(token, &stosint);
    }
}


int main(int argc, const char * argv[]) {
    int iloscRownan;
    std::cin >> iloscRownan;

    List arrayLists[iloscRownan];
    //NodeString *headery = new NodeString[iloscRownan];



    //aby najpierw wpisac wszystko pozniej liczyc 2 osobne petle
    //konversia
    for (int i = 0; i < iloscRownan ; i++){
        conversionONP(&arrayLists[i]);
    }

    //kalkulacje + wyswietlanie
    for (int i = 0; i < iloscRownan ; i++){
        calculationsONP(&arrayLists[i]);
    }

    //delete[] headery;
    return 0;
}

