#include "list.h"
#include <time.h>

using namespace std;

// Constructor por defecto
template<typename T>
List<T>::List()
{
    num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->set_node(m_head);
        m_head = new_node;

        while (temp) {
            temp = temp->get_node();
        }
    }
    num_nodes++;
}

// Insertar al final
template<typename T>
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->get_node() != NULL) {
            temp = temp->get_node();
        }
        temp->set_node(new_node) ;
    }
    num_nodes++;
}

// Insertar de manera ordenada
template<typename T>
void List<T>::add_sort(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        if (m_head->get_data() > data_) {
            new_node->set_node(m_head) ;
            m_head = new_node;
        } else {
            while ((temp->get_node() != NULL) && (temp->get_node()->get_data() < data_)) {
                temp = temp->get_node();
            }
            new_node->set_node(temp->get_node());
            temp->set_node(new_node);
        }
    }
    num_nodes++;
}

// Llenar la Lista aleatoriamente para enteros
template<typename T>
void List<T>::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100);
    }
}

// Usado por el método intersección
template<typename T>
void insert_sort(T a[], int size)
{
    T temp;
    for (int i = 0; i < size; i++) {
        for (int j = i-1; j>= 0 && a[j+1] < a[j]; j--) {
            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }
}



// Invertir la lista
template<typename T>
void List<T>::invertir()
{
    Node<T> *prev = NULL;
    Node<T> *next = NULL;
    Node<T> *temp = m_head;

    while (temp) {
        next = temp->get_node();
        temp->set_node(prev) ;
        prev = temp;
        temp = next;
    }
    m_head = prev;
}


// Imprimir la Lista
template<typename T>
void List<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->get_node()) cout << "nulo";
                temp = temp->get_node();
        }
  }
  cout << "\n\n";
}


template<typename T>
void List<T>::sort()// Orden ascendente
{
    T temp_data;
    Node<T> *aux_node = m_head;
    Node<T> *temp = aux_node;

    while (aux_node) {
        temp = aux_node;

        while (temp->get_node()) {
            temp = temp->get_node();

            if (aux_node->get_data() > temp->get_data()) {
                temp_data = aux_node->get_data();
                aux_node->set_data(temp->get_data());
                temp->set_data(temp_data);
            }
        }

        aux_node = aux_node->get_node();
    }
}

// Eliminar por posición del nodo
template<typename T>
void List<T>::del_pos(int pos)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->get_node();

    if (pos < 1 || pos > num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->get_node();
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node<T> *aux_node = temp1;
                temp->set_node(temp1->get_node());
                delete aux_node;
                num_nodes--;
            }
            temp = temp->get_node();
            temp1 = temp1->get_node();
        }
    }
}

// Buscar el dato de un nodo
template<typename T>
void List<T>::buscar_lista(T data_)
{
    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->get_data() == data_) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->get_node();
        cont++;
    }

    if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;
}



template<typename T>
List<T>::~List() {}
