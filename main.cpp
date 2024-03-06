
#include <iostream>

class Node {
public:
    Node *next;
    char value;
    Node(char value) : value(value), next(nullptr) {}
};

class Stos {
private:
    Node *top;
public:
    Stos() : top(nullptr) {}

    ~Stos() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
    void push(char liczbaNowa) {
        Node *newNode = new Node(liczbaNowa);
        newNode->next = top;
        top = newNode;
    }
    void pop(){
        Node *zmienna = top;
        top = top->next;
        delete zmienna;
    }
    char topValue(){
        return top->value;
    }
};

class Kolejka {
private:
    Node *front;
    Node *end;
public:
    Kolejka() : front(nullptr), end(nullptr) {}

    ~Kolejka() {
        while (!isEmpty()) {
            zKolejki();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
    void doKolejki (char value) {
        Node *newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            end = newNode;
        } else {
            end->next = newNode;
            end = newNode;
        }
    }
    char zKolejki () {
        char zmiennaDisp;
        if (!isEmpty()) {
            Node * zmienna = front;
            zmiennaDisp = front->value;
            front = front->next;

            if (front == nullptr) {
                end = nullptr; // If the queue becomes empty after dequeue
            }

            delete zmienna;
        }
        return zmiennaDisp;
    }
};


void conversionONP (Kolejka *kolejka){
    char token;
    Stos stosZnakow;

    while (token != '.') {
        std::cin >> token;

        switch (token) {
            case '*':
                break;
            case '/':
                break;
            case '+':
                break;
            case '-':
                break;
            case '(':
                stosZnakow.push('(');
                break;
            case ')':
                while (stosZnakow.topValue() != '('){
                    kolejka->doKolejki(stosZnakow.topValue());
                    stosZnakow.pop();
                }
                stosZnakow.pop();
                break;
            default:
                kolejka->doKolejki(token);
        }
    }
    std::cout << "\n";
}
void calculationsONP (){

}


int main(int argc, const char * argv[]) {
    int iloscRownan;
    std::cin >> iloscRownan;

    Kolejka kolejki[iloscRownan];

    //aby najpierw wpisac wszystko pozniej liczyc 2 osobne petle
    //konversia
    for (int i = 0; i<< iloscRownan ; i++){
        conversionONP(&kolejki[i]);
    }

    //kalkulacje + wyswietlanie
    for (int i = 0; i<< iloscRownan ; i++){
        calculationsONP();
    }


    return 0;
}

