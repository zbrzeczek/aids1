
#include <iostream>
#include <cstring>
//#include "StosString.h"
//#include "StosInt.h"
#include "List.h"
#include "Stos.h"

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

void znakDoListy(Stos *stosZnakow, List *lista, int *zmiennaMaxMin) {
    if (stosZnakow->topValue()->stringValue[0] == 'M'){
        char *zmienna = stosZnakow->topValue()->stringValue;
        char *liczbaMinMax = intToString(zmiennaMaxMin);

        char *newValue = new char[strlen(liczbaMinMax) + 4];
        strcpy(newValue, zmienna);
        strcat(newValue, liczbaMinMax);

        newValue[strlen(liczbaMinMax) + 4] = '\0';

        lista->insertChar(newValue);
        //stosMaxMin->pop();
        //if (!stosMaxMin->isEmpty()) stosMaxMin->add(1);
        delete[] newValue;
    }
    else {
        lista->insertChar(stosZnakow->topValue()->stringValue);
    }
    stosZnakow->pop();
}

void calculationsOperator(char *token, Stos *stos, int *calculations) {
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
            op1 = stos->topValue()->intValue;
            stos->pop();
            op2 = stos->topValue()->intValue;
            stos->pop();
            if (strncmp(token, "MAX", 3) == FALSE) result = max(op1, op2);
            else result = min(op1, op2);
            stos->push(result);
        }
        delete[] compareMaxMin;
    }
    else {
        op1 = stos->topValue()->intValue;
        stos->pop();
        if (strcmp(token, "N") == FALSE) {
            result = -op1;
        }
        else if (strcmp(token, "IF") == FALSE){
            op2 = stos->topValue()->intValue;
            stos->pop();
            int op3 = stos->topValue()->intValue;
            stos->pop();
            result = op3 > 0 ? op2 : op1;
        }
        else if (strcmp(token, "*") == FALSE){
            op2 = stos->topValue()->intValue;
            stos->pop();
            result = op1*op2;
        }
        else if (strcmp(token, "/") == FALSE){
            op2 = stos->topValue()->intValue;
            stos->pop();
            if(op1 == 0) *calculations = FALSE;
            else result = op2/op1;
        }
        else if (strcmp(token, "+") == FALSE) {
            op2 = stos->topValue()->intValue;
            stos->pop();
            result = op1+op2;
        }
        else {
            op2 = stos->topValue()->intValue;
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
    Stos stosZnakow;
    Stos stosMaxMin;
    //List lista(head);

    std::cin >> token;
    while (token != '.') {

        if(token == ' ') std::cin >> token;
        if(token == '.') break;

        Node *newItem = new Node;
        int tokenInt = 0;
        int num =0;

        while (token != ' ') {
            if (isdigit(token)) {
                newItem->isInt = TRUE;
                num = num * 10 + (token - '0');
            }
            else {
                newItem->isInt = FALSE;
                temp[tokenInt] = token;
                tokenInt++;
            }
            std::cin.get(token);
        }

        if (newItem->isInt) newItem->value.intValue = num;
        else {
            temp[tokenInt] = '\0'; // Null-terminate the string
            newItem->value.stringValue = new char[tokenInt + 2];
            strcpy(newItem->value.stringValue, temp);
        }

        if (newItem->isInt){
            lista->insert(newItem->value.intValue);
        }
        else if (newItem->value.stringValue[0] == '(') {
            stosMaxMin.push(1);
            stosZnakow.push(newItem->value.stringValue);
        }
        else if (newItem->value.stringValue[0] == ')') {

            while (strcmp(stosZnakow.topValue()->stringValue, "(") != FALSE) {
                znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
                    /*lista->insert(stosZnakow.topValue());
                    stosZnakow.pop();*/
            }
            if (!stosMaxMin.isEmpty()) {
                zmiennaMaxMin = stosMaxMin.topValue()->intValue;
                stosMaxMin.pop();
            }

            stosZnakow.pop();
        }
        else if (newItem->value.stringValue[0] == ','){
            if (!stosMaxMin.isEmpty()) stosMaxMin.add(1);

            //do przypadkow gdy w min/max/if jest jakies rownanie w srodku ex. min( 1 , 2 * 5 + 6 , 2 ) .
            while (stosZnakow.topValue()->stringValue[0] != '('){
                znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
                /*lista->insert(stosZnakow.topValue());
                stosZnakow.pop();*/
            }
        }
        else {
            //ogarnienie liczby przy max min
            //if (strcmp(string, "MIN") == FALSE || strcmp(string, "MAX") == FALSE) stosMaxMin.push(1);
            //if (strcmp(string, "IF") == FALSE && !stosMaxMin.isEmpty() && (strcmp(string, "MAX") == FALSE || strcmp(string, "MIN") == FALSE)) stosMaxMin.add(-2);

            while (!stosZnakow.isEmpty() && priority(stosZnakow.topValue()->stringValue[0]) >= priority(newItem->value.stringValue[0])) {
                if (stosZnakow.topValue()->stringValue[0] == 'N' && priority(stosZnakow.topValue()->stringValue[0]) == priority(newItem->value.stringValue[0])) break;
                znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
                if (stosZnakow.isEmpty()) break;
            }

            stosZnakow.push(newItem->value.stringValue);
        }

        delete newItem;
    }
    while (!stosZnakow.isEmpty()){
        znakDoListy(&stosZnakow, lista, &zmiennaMaxMin);
        //lista->insert(stosZnakow.topValue());
        //1stosZnakow.pop();
    }
}

void calculationsONP (List *lista){
    Node *token;
    Stos stosint;
    int calcualtions = TRUE;

    lista->disp();
    printf("\n");

    while(!lista->isEmpty()) {
        token = lista->getHeadValue();
        if (token->isInt) {
            stosint.push(token->value.intValue);
        }
        else {
            calculationsOperator(token->value.stringValue, &stosint, &calcualtions);
            if (calcualtions == FALSE) break;
        }
        lista->del();
    }
    if (calcualtions == FALSE) printf("ERROR\n");
    else printf("%d\n", stosint.topValue()->intValue);
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

