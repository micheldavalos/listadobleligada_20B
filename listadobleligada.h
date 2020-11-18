#ifndef LISTA_DOBLE_LIGADA_H
#define LISTA_DOBLE_LIGADA_H

#include <iostream>
using namespace std;

template <class T>
class ListaDobleLigada
{
public:
    ListaDobleLigada();
    ~ListaDobleLigada();
    
    bool empty();

    // insertar
    void push_front(const T &dato);
    void push_back(const T &dato);

    size_t size();

    ListaDobleLigada& operator<<(const T &dato)
    {
        push_back(dato);

        return *this;
    }

    // recorridos
    void print();
    void print_reverse();
    T* front();
    T* back();

private:
    struct Nodo {
        T dato;
        Nodo *sig;
        Nodo *ant;

        Nodo(const T &dato, Nodo *sig = nullptr, Nodo *ant = nullptr)
        : dato(dato), sig(sig), ant(ant) {}
    };

    Nodo *head;
    Nodo *tail;
    size_t cont;
};

template <class T>
ListaDobleLigada<T>::ListaDobleLigada()
{
    head = nullptr;
    tail = nullptr;
    cont = 0;
}

template <class T>
ListaDobleLigada<T>::~ListaDobleLigada()
{
    // eliminar todos los nodos
}

template <class T>
bool ListaDobleLigada<T>::empty()
{
    return cont == 0;
}

template <class T>
void ListaDobleLigada<T>::push_front(const T &dato)
{
    Nodo *nodo = new Nodo(dato, head);
    if (cont == 0) { // empty()
        head = nodo;
        tail = nodo;
    } else {
        head->ant = nodo;
        head = nodo;
    }
    cont++;
}

template <class T>
void ListaDobleLigada<T>::push_back(const T &dato)
{
    Nodo *nodo = new Nodo(dato, nullptr, tail);
    if (cont == 0) {
        head = nodo;
        tail = nodo;
    } else {
        tail->sig = nodo;
        tail = nodo;
    }
    cont++;
}

template <class T>
size_t ListaDobleLigada<T>::size()
{
    return cont;
}

template <class T>
void ListaDobleLigada<T>::print()
{
    Nodo *temp = head;

    while (temp != nullptr) 
    {
        cout << temp->dato << endl;
        temp = temp->sig;
    }    
}

template <class T>
void ListaDobleLigada<T>::print_reverse()
{
    Nodo *temp = tail;

    while (temp != nullptr)
    {
        cout << temp->dato << endl;
        temp = temp->ant;
    }    
}

template <class T>
T* ListaDobleLigada<T>::front()
{
    if (empty()) {
        return nullptr;
    } else {
        return &head->dato;
    }
}

template <class T>
T* ListaDobleLigada<T>::back()
{
    if (empty()) {
        return nullptr;
    } else {
        return &tail->dato;
    }
}


#endif