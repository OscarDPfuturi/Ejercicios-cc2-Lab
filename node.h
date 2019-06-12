#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node{
    Node<T> *next;
    T data;
public:
    Node();
    Node(T);
    ~Node();

    Node *get_node(){return next;};
    void set_node(Node *_next){next = _next;};
    T get_data(){return  data;};
    void set_data(T _data){data = _data;};

    void delete_all();
    void print();
};

#endif // NODE_H
