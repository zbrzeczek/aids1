
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

char * intToString(int *num) {
    int numDigits = 0;
    int temp = *num;
    while (temp != 0) {
        temp /= 10;
        numDigits++;
    }
    // Allocate memory for the character array
    char* result = new char[numDigits + 1]; // +1 for the null terminator

    // Convert the integer to characters
    int index = numDigits - 1;
    while (*num != 0) {
        result[index--] = '0' + (*num % 10); // Convert digit to character
        *num /= 10;
    }
    result[numDigits] = '\0'; // Null terminator

    return result;
}

int priority (const char char1){
    if (char1 == '(' || char1 == ')'){
        return -1;
    }
    else if (char1 == 'M' || char1 == 'I' || char1 == 'N'){
        return 2;
    }
    else if (char1 == '*' || char1 == '/') {
        return 1;
    }
    else return 0;
}

void znakDoListy(StosString *stosZnakow, List *lista, int *zmiennaMaxMin) {
    if (stosZnakow->topValue()[0] == 'M'){
        char *zmienna = stosZnakow->topValue();
        char *liczbaMinMax = intToString(zmiennaMaxMin);

        char *newValue = new char[strlen(liczbaMinMax) + 4];
        strcpy(newValue, zmienna);
        strcat(newValue, liczbaMinMax);

        newValue[strlen(liczbaMinMax) + 4] = '\0';

        lista->insert(newValue);
        //stosMaxMin->pop();
        //if (!stosMaxMin->isEmpty()) stosMaxMin->add(1);
        delete[] newValue;
    }
    else {
        lista->insert(stosZnakow->topValue());
    }
    stosZnakow->pop();
}

void calculationsOperator(char *token, StosInt *stos, int *calculations) {
    int result;
    int op1, op2;
    printf("%s ", token);
    stos->display();

    if (strlen(token) > 3) {
        char *tempptr = token+3;
        char *compareMaxMin = new char[4];
        strncpy(compareMaxMin, token, 3);
        int iloscMinMax = stringToInt(tempptr);
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
            int op3 = stos->topValue();
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

    printf("\n");
}

void conversionONP (List *lista){
    int zmiennaMaxMin;
    char token;
    char temp[100];
    StosString stosZnakow;
    StosInt stosMaxMin;
    //List lista(head);

    std::cin >> token;
    while (token != '.') {

        if(token == ' ') std::cin >> token;
        if(token == '.') break;

        int tokenInt = 0;

        while (token != ' ') {
            temp[tokenInt] = token;
            tokenInt++;

            std::cin.get(token);
        }

        temp[tokenInt] = '\0'; // Null-terminate the string
        char* string = new char[tokenInt + 2];
        strcpy(string, temp);

        if (isdigit(string[0])){
            lista->insert(string);
        }
        else if (string[0] == '(') {
            stosMaxMin.push(1);
            stosZnakow.push(string);
        }
        else if (string[0] == ')') {

            while (strcmp(stosZnakow.topValue(), "(") != FALSE) {
                znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
                    /*lista->insert(stosZnakow.topValue());
                    stosZnakow.pop();*/
            }
            if (!stosMaxMin.isEmpty()) {
                zmiennaMaxMin = stosMaxMin.topValue();
                stosMaxMin.pop();
            }

            stosZnakow.pop();
        }
        else if (string[0] == ','){
            if (!stosMaxMin.isEmpty()) stosMaxMin.add(1);

            //do przypadkow gdy w min/max/if jest jakies rownanie w srodku ex. min( 1 , 2 * 5 + 6 , 2 ) .
            while (stosZnakow.topValue()[0] != '('){
                znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
                /*lista->insert(stosZnakow.topValue());
                stosZnakow.pop();*/
            }
        }
        else {
            //ogarnienie liczby przy max min
            //if (strcmp(string, "MIN") == FALSE || strcmp(string, "MAX") == FALSE) stosMaxMin.push(1);
            //if (strcmp(string, "IF") == FALSE && !stosMaxMin.isEmpty() && (strcmp(string, "MAX") == FALSE || strcmp(string, "MIN") == FALSE)) stosMaxMin.add(-2);

            while (!stosZnakow.isEmpty() && priority(stosZnakow.topValue()[0]) >= priority(string[0])) {
                if (stosZnakow.topValue()[0] == 'N' && priority(stosZnakow.topValue()[0]) == priority(string[0])) break;
                znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
                if (stosZnakow.isEmpty()) break;
            }

            stosZnakow.push(string);
        }

        delete []string;
    }
    while (!stosZnakow.isEmpty()){
        znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
        //lista->insert(stosZnakow.topValue());
        //1stosZnakow.pop();
    }
}

void calculationsONP (List *lista){
    char *token;
    StosInt stosint;
    int calcualtions = TRUE;

    lista->disp();
    printf("\n");

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
    if (calcualtions == FALSE) printf("ERROR\n");
    else printf("%d\n", stosint.topValue());
    stosint.pop();
}


int main() {
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
        printf("\n");
    }

    delete[] arrayLists;
    return 0;
}

