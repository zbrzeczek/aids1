#include <iostream>


class Node {
private:
    int *back;
    int *front;
    int value;
public:
    Node(int *front, int *back);
};

class Stos {
private:
    int rozmiar = 0;
    int *wskPrzedni;
    int *wskTylni;
public:
    Stos(int *liczba) : wskPrzedni(liczba){
        wskTylni = new Node();
        rozmiar++;
    }
    void push(int liczbaNowa) {
        rozmiar++;
        wsk++;
        *wsk = liczbaNowa;
    }
    int pop(){
        rozmiar--;
        int zmienna = *wsk;
        wsk--;
        return zmienna;
    }
    int size(){
        return rozmiar;
    }
    int top(){
        return *wsk;
    }
};

int main(int argc, const char * argv[]) {
    int liczbaRownan;
    std::cin >> liczbaRownan;


    const int rozmiarStos = 10;
    int liczbaPodana = 0;


    Stos stos(&liczbaPodana);

    stos.push(3);
    std::cout << stos.top() << "\n";

    stos.push(5);

    std::cout << stos.pop() << "\n" << stos.top() << "\n";

    return 0;
}

