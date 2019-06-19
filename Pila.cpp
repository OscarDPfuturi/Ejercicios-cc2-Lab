#include <iostream>

using namespace std;

template <typename T>
class Nodo{////////////////////////////////////clase Nodo////////////////////////////
    T dato;
    Nodo<T> *sig;
public:
    Nodo(){};

    Nodo<T> *get_nodo(){return sig;};
    void set_nodo(Nodo<T> *_sig){sig = _sig;};
    T get_dato(){return  dato;};
    void set_dato(T _dato){dato = _dato;};
};

template <typename T>
class Pila{//////////////////////////////////clase Pila///////////////////////////////////
    Nodo<T> *raiz;
public:
    Pila(){raiz = NULL;};
    ~Pila();

    void insertar(T);
    T extraer();
    void imprimir();
};

template <typename T>
void Pila<T>::insertar(T x){
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>();
    nuevo->set_dato(x);
    if (raiz == NULL){
        raiz = nuevo;
        nuevo->set_nodo(NULL);
    }
    else{
        nuevo->set_nodo(raiz);
        raiz = nuevo;
    }
}

template <typename T>
T Pila<T>::extraer(){
    if (raiz != NULL){
        T informacion = raiz->get_dato();
        Nodo<T> *bor = raiz;
        raiz = raiz->get_nodo();
        delete bor;
        return informacion;
    }
    else{
        return -1;
    }
}

template <typename T>
void Pila<T>::imprimir(){
    Nodo<T> *reco = raiz;
    cout << "Listado de todos los elementos de la pila.\n";
    while (reco != NULL){
        cout << reco->get_dato() << "-";
        reco = reco->get_nodo();
    }
    cout << "\n";
}

template <typename T>
Pila<T>::~Pila(){
    Nodo<T> *reco = raiz;
    Nodo<T> *bor;
    while (reco != NULL){
        bor = reco;
        reco = reco->get_nodo();
        delete bor;
    }
}



template <typename T>
void menu(Pila<T> *pila){
    int opc;
    T ele;
    do {
        cout<<"Elija una opción: "<<endl;
        cout<<"1.Insertar elemento. "<<endl;
        cout<<"2.Extraer elemento. "<<endl;

        cout<<"4.Mostrar contenido. "<<endl;
        cout<<"5.Salir. \n:.";
        cin >> opc;
        switch(opc){
        case 1:
            cout<<"Ingrese elemento: "; cin >> ele;
            pila->insertar(ele); break;
        case 2:
            cout<<"Extraemos de la pila: "<<pila->extraer()<<"\n";
            pila->extraer(); break;
        case 3:
            break;
        case 4:
            pila->imprimir(); break;
        }
    }while (opc!=5);
}

int main(){
    Pila<int> *pila1;
    pila1 = new Pila<int>();

    menu(pila1);
    delete pila1;
    cin.get();
}
