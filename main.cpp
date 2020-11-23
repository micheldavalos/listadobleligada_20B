#include <iostream>
#include "listadobleligada.h"
using namespace std;

int main() {
    ListaDobleLigada<int> enteros;

    enteros.push_front(1);
    enteros.push_front(2);
    enteros.push_front(3);

    // enteros.push_back(4);
    // enteros.push_back(5);
    // enteros.push_back(6);
    enteros << 4 << 5 << 6;

    // for (size_t i = 0; i < enteros.size(); i++)
    // {
    //     cout << *enteros[i] << endl;
    // }
    
    enteros.insert(0, 3); // insertar un 0 en la posicion 3
    enteros.erase(1);

    cout << "cantidad: " << enteros.size() << endl;

    enteros.print();
    cout << endl;
    /*enteros.print_reverse();

    int *front = enteros.front();

    if (front) {
        cout << "front: " << *front << endl;
    }

    int *back = enteros.back();
    if (back) {
        cout << "back: " << *back << endl;
    }

    enteros.pop_front();
    cout << endl;
    enteros.print();
    cout << endl;
    enteros.pop_back();
    enteros.print();

    enteros.~ListaDobleLigada();
    cout << "cantidad: " << enteros.size() << endl;*/


    return 0;
}