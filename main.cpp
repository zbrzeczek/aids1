
#include <iostream>
#include <cstring>
#include "StosString.h"
#include "StosInt.h"
#include "List.h"

#define TRUE 1
#define FALSE 0
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int stringToInt (char *string) {
    int result = 0;

    while (*string != '\0') {
        result = result * 10 + (*string - '0');
        string++;
    }

    return result;
}

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

void znakDoListy(StosString *stosZnakow, List *lista, int zmiennaMaxMin) {
    if (strcmp(stosZnakow->topValue(), "MIN") == FALSE || strcmp(stosZnakow->topValue(), "MAX") == FALSE){
        char *zmienna = stosZnakow->topValue();
        char *liczbaMinMax = intToString(zmiennaMaxMin);

        char *newValue = new char[strlen(stosZnakow->topValue()) + strlen(liczbaMinMax) + 1];
        strcpy(newValue, zmienna);
        strcat(newValue, liczbaMinMax);

        newValue[strlen(stosZnakow->topValue()) +1 ] = '\0';

        lista->insert(newValue);
        //stosMaxMin->pop();
        //if (!stosMaxMin->isEmpty()) stosMaxMin->add(1);
    }
    else {
        lista->insert(stosZnakow->topValue());
    }
    stosZnakow->pop();
}

void calculationsOperator(char *token, StosInt *stos, int *calculations) {
    int iloscMinMax;
    int result;
    int op1, op2, op3;
    std::cout << token << " ";
    stos->display();

    if (strlen(token) > 3) {
        char *tempptr = token+3;
        char *compareMaxMin = new char[4];
        strncpy(compareMaxMin, token, 3);
        iloscMinMax = stringToInt(tempptr);
        for (int i =0; i<iloscMinMax-1; i++){
            op1 = stos->topValue();
            stos->pop();
            op2 = stos->topValue();
            stos->pop();
            if (strncmp(token, "MAX", 3) == FALSE) result = max(op1, op2);
            else result = min(op1, op2);
            stos->push(result);
        }
        delete[] compareMaxMin;
    }
    else {
        op1 = stos->topValue();
        stos->pop();
        if (strcmp(token, "N") == FALSE) {
            result = -op1;
        }
        else if (strcmp(token, "IF") == FALSE){
            op2 = stos->topValue();
            stos->pop();
            op3 = stos->topValue();
            stos->pop();
            result = op3 > 0 ? op2 : op1;
        }
        else if (strcmp(token, "*") == FALSE){
            op2 = stos->topValue();
            stos->pop();
            result = op1*op2;
        }
        else if (strcmp(token, "/") == FALSE){
            op2 = stos->topValue();
            stos->pop();
            if(op1 == 0) *calculations = FALSE;
            else result = op2/op1;
        }
        else if (strcmp(token, "+") == FALSE) {
            op2 = stos->topValue();
            stos->pop();
            result = op1+op2;
        }
        else {
            op2 = stos->topValue();
            stos->pop();
            result = op2 - op1;
        }
        stos->push(result);
    }

    std::cout << std::endl;
}

void conversionONP (List *lista){
    int zmiennaMaxMin;
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
            stosMaxMin.push(1);
            stosZnakow.push(string);
        }
        else if (strcmp(string, ")") == FALSE) {
            if (!stosMaxMin.isEmpty()) {
                zmiennaMaxMin = stosMaxMin.topValue();
                stosMaxMin.pop();
            }
            while (strcmp(stosZnakow.topValue(), "(") != FALSE) {
                znakDoListy(&stosZnakow, lista, zmiennaMaxMin);
                    /*lista->insert(stosZnakow.topValue());
                    stosZnakow.pop();*/
            }

            stosZnakow.pop();
        }
        else if (strcmp(string, ",") == FALSE){
            if (!stosMaxMin.isEmpty()) stosMaxMin.add(1);

            //do przypadkow gdy w min/max/if jest jakies rownanie w srodku ex. min( 1 , 2 * 5 + 6 , 2 ) .
            while (strcmp(stosZnakow.topValue(), "(") != FALSE){
                znakDoListy(&stosZnakow, lista, zmiennaMaxMin);
                /*lista->insert(stosZnakow.topValue());
                stosZnakow.pop();*/
            }
        }
        else {
            //ogarnienie liczby przy max min
            //if (strcmp(string, "MIN") == FALSE || strcmp(string, "MAX") == FALSE) stosMaxMin.push(1);
            if (strcmp(string, "IF") == FALSE && !stosMaxMin.isEmpty()) stosMaxMin.add(-2);

            if (!stosZnakow.isEmpty()) {
                if (strcmp(string, "N") != FALSE){
                    while (priority(stosZnakow.topValue()) >= priority(string)) {
                        znakDoListy(&stosZnakow, lista, zmiennaMaxMin);
                        if (stosZnakow.isEmpty()) break;
                    }
                }
                else {
                    while (priority(stosZnakow.topValue()) > priority(string)) {
                        znakDoListy(&stosZnakow, lista, zmiennaMaxMin);
                        if (stosZnakow.isEmpty()) break;
                    }
                }
            }
            stosZnakow.push(string);
        }

        delete []temp;
        delete []string;
    }
    while (!stosZnakow.isEmpty()){
        znakDoListy(&stosZnakow, lista, zmiennaMaxMin);
        //lista->insert(stosZnakow.topValue());
        //1stosZnakow.pop();
    }
}

void calculationsONP (List *lista){
    char *token;
    StosInt stosint;
    int calcualtions = TRUE;

    lista->disp();
    std::cout << std::endl;

    while(!lista->isEmpty()) {
        token = lista->getHeadValue();
        if (isdigit(token[0])) {
            stosint.push(stringToInt(token));
        }
        else {
            calculationsOperator(token, &stosint, &calcualtions);
            if (calcualtions == FALSE) break;
        }
        lista->del();
    }
    if (calcualtions == FALSE) std::cout << "ERROR" << std::endl;
    else std::cout << stosint.topValue() << std::endl;
    stosint.pop();
}


int main(int argc, const char * argv[]) {
    int iloscRownan;
    std::cin >> iloscRownan;

    List* arrayLists = new List[iloscRownan];
    //NodeString *headery = new NodeString[iloscRownan];



    //aby najpierw wpisac wszystko pozniej liczyc 2 osobne petle
    //konversia
    for (int i = 0; i < iloscRownan ; i++){
        conversionONP(&arrayLists[i]);
    }

    //kalkulacje + wyswietlanie
    for (int i = 0; i < iloscRownan ; i++){
        calculationsONP(&arrayLists[i]);
        std::cout << std::endl;
    }

    delete[] arrayLists;
    return 0;
}

