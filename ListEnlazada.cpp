#include <iostream>
//#include <stdio.h>
#include <time.h>
#include <stdlib.h> //operacion con srand rand

using namespace std;

template <typename T>
class Node{//////////////////clase Node///////////////////////////
    Node<T> *next;
    T data;
public:
    Node();
    Node(T);
    ~Node(){};

    Node<T> *get_node(){return next;};
    void set_node(Node<T> *_next){next = _next;};
    T get_data(){return  data;};
    void set_data(T _data){data = _data;};

    void delete_all();
    void print();
};


// Constructor por defecto
template<typename T>
Node<T>::Node(){
    data = NULL;
    next = NULL;
}

// Constructor por parámetro
template<typename T>
Node<T>::Node(T data_){
    data = data_;
    next = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void Node<T>::delete_all(){
    if (next)
        next->delete_all();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void Node<T>::print(){
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << data << " ";
}


template <typename T>
class List{////////////////////////////////clase List//////////////////////////////////////
    Node<T> *m_head;
    int num_nodes;
public:
    //friend class Iterator;
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

    //Iterator *crearIterator()const;
};


// Constructor por defecto
template<typename T>
List<T>::List(){
    num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
template<typename T>
void List<T>::add_head(T data_){
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
void List<T>::add_end(T data_){
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
void List<T>::add_sort(T data_){
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
void List<T>::fill_random(int dim){
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        add_end(rand() % 100);
    }
}



// Invertir la lista
template<typename T>
void List<T>::invertir(){
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
void List<T>::print(){
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
void List<T>::sort(){// Orden ascendente
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
void List<T>::del_pos(int pos){
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
void List<T>::buscar_lista(T data_){
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
    cout << "\n\n";
}

template<typename T>
List<T>::~List() {}

//fuente////////////////////https://sourcemaking.com/design_patterns/iterator/cpp/1


/*template <typename T>
class Iterator{/////////////////////////////clase Iterator///////////////////////////////////
    Node<T> *nd;
    int index;
public:
    Iterator(Node<T> *_nd){ nd = _nd;}

    void first(){index = 0;}
    void next(){index++;}
    bool hecho(){return nd->get_data()+1;}

    int Item_actual(){return nd->List[index];}

};

template <typename T>
Iterator *Iterator<T>::crearIterator()const{
    return new Iterator(this);
}
bool operator == (const List &l, const List &r)
{
  Iterator *itl = l.crearIterator();
  Iterator *itr = r.crearIterator();

  for (itl->first(), itr->first(); !itl->hecho(); itl->next(), itr->next())
    if (itl->Item_actual() != itr->Item_actual())
      break;
  bool ans = itl->hecho() && itr->hecho();
  delete itl;
  delete itr;
  return ans;
}*/

int main()/////////////////funcion principal/////////////////////////
{
    List<int> list_1;
    List<char> list_2;
    int ele,opc;

    int dim;

    cout << "Ingrese la dimension de la lista: " << endl;
    cin >> dim;
    for (int i=0; i<dim; i++){
        cout<<"Ingrese elemento: "; cin>>ele;
        list_1.add_head(ele);
    }
    do {
        cout<<"Elija una opción: "<<endl;
        cout<<"1.Insertar elemento al inicio. "<<endl;
        cout<<"2.Insertar elemento al final. "<<endl;
        cout<<"3.Ordenar la lista. "<<endl;
        cout<<"4.Eliminar un elemento. "<<endl;
        cout<<"5.Buscar un elemento. "<<endl;
        cout<<"6.Mostrar lista. "<<endl;
        cout<<"7.Salir. \n:.";
        cin >> opc;
        switch(opc){
        case 1:
            cout<<"Ingrese elemento: "; cin >> ele;
            list_1.add_head(ele); break;
        case 2:
            cout<<"Ingrese elemento: "; cin>>ele;
            list_1.add_end(ele); break;
        case 3:
            list_1.sort(); break;
        case 4:
            int pos;
            cout<<"Ingrese la posicion a eliminar: "; cin>>pos;
            list_1.del_pos(pos); break;
        case 5:
            int dato;
            cout<<"Ingrese elemento a buscar: "; cin>>dato;
            list_1.buscar_lista(dato); break;
        case 6:
            list_1.print(); break;
        }
    }while (opc!=7);

    return 0;
}
