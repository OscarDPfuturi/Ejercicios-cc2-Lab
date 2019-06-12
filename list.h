#ifndef LIST_H
#define LIST_H

#include <iostream>
//#include <string>
#include <stdlib.h> //operacion con srand rand

#include "node.h"
#include "node.cpp"

using namespace std;

template <class T>

class List
{
public:
    List();
    ~List();

    void add_head(T);
    void add_end(T);
    void add_sort(T);//agrega y ordena

    void buscar_lista(T);//busqueda

    void fill_random(int);

    void invertir();

    void print();
    void del_pos(int);//elimina una posicion

    void sort();

private:
    Node<T> *m_head;
    int num_nodes;
};

#endif // LIST_H
