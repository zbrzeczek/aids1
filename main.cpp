
#include <iostream>


struct NodeString {
    NodeString *next;
    char *value;
};

struct NodeInt{
    NodeInt *next;
    int value;
};

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Don't forget to null-terminate the destination string
}

class StosString {
private:
    NodeString *top;
public:
    StosString() : top(nullptr) {}

    ~StosString() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
    void push(char *valueNowe) {
        NodeString *newNode = new NodeString;
        newNode->value = new char[sizeof(valueNowe) + 1];
        my_strcpy(newNode->value, valueNowe);
        newNode->next = top;
        top = newNode;
    }
    void pop(){
        NodeString *zmienna = top;
        top = top->next;
        delete[] zmienna->value;
        delete zmienna;
    }
    char *topValue(){
        return top->value;
    }
};

class StosInt {
private:
    NodeInt *top;
public:
    StosInt() : top(nullptr) {}

    ~StosInt() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
    void push(int liczbaNowa) {
        NodeInt *newNode = new NodeInt;
        newNode->value = liczbaNowa;
        newNode->next = top;
        top = newNode;
    }
    void pop(){
        NodeInt *zmienna = top;
        top = top->next;
        delete zmienna;
    }
    int topValue(){
        return top->value;
    }
};

void displayListString(NodeString *head) {
    NodeString *current = head;

    while (current != nullptr) {
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

void conversionONP (NodeString *head){
    char *string;
    char token;
    int tokenInt = 0;
    StosString stosZnakow;

    NodeString *zmienna = new NodeString;

    while (token != '.') {
        while (token != ' '){
            std::cin >> token;
            string[tokenInt] = token;
            string[tokenInt+1] = '\0';
            tokenInt++;
        }
        if (string == "MAX" || string== "MIN" || string == "IF" || string== "n") {

        }
        else if (string == "*" || string== "/"){

        }
        else if (string == "("){
            stosZnakow.push('(');
        }

        switch (string) {
            case :
            case 'MIN':

            case '*':
            case '/':

                break;
            case '+':
            case '-':
                break;
            case '(':
                stosZnakow.push('(');
                break;
            case ')':
                while (stosZnakow.topValue() != '(') {
                    Node *nowy;
                    nowy = (Node *) malloc(sizeof(Node));
                    nowy->value = stosZnakow.topValue();
                    nowy->next = NULL;
                    zmienna->next = nowy;
                    zmienna = nowy;
                    stosZnakow.pop();
                }
                stosZnakow.pop();
                break;
            default:
                if (zmienna == nullptr) {
                    zmienna->value = token;
                    zmienna->next = NULL;
                } else {
                    Node *nowy;
                    nowy = (Node *) malloc(sizeof(Node));
                    nowy->value = token;
                    nowy->next = NULL;
                    zmienna->next = nowy;
                    zmienna = nowy;
                }
        }
    }
    std::cout << "\n";
    displayList(head);
}
void calculationsONP (){

}


int main(int argc, const char * argv[]) {
    int iloscRownan;
    std::cin >> iloscRownan;

    Node headery[iloscRownan];


    //aby najpierw wpisac wszystko pozniej liczyc 2 osobne petle
    //konversia
    for (int i = 0; i<< iloscRownan ; i++){
        conversionONP(&headery[i]);
    }

    //kalkulacje + wyswietlanie
    for (int i = 0; i<< iloscRownan ; i++){
        calculationsONP();
    }


    return 0;
}

