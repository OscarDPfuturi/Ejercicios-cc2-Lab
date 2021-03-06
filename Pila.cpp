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
    void extraer();
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
void Pila<T>::extraer(){
    if (raiz != NULL){
        T informacion = raiz->get_dato();
        Nodo<T> *bor = raiz;
        raiz = raiz->get_nodo();
        delete bor;
        cout<<"Se elimino "<<informacion<<" de la pila."<<endl;
    }
    else{
        cout<<"La pila esta vacia."<<endl;
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
        cout<<"Elija una opci�n: "<<endl;
        cout<<"1.Insertar elemento. "<<endl;
        cout<<"2.Extraer elemento. "<<endl;

        cout<<"3.Mostrar contenido. "<<endl;
        cout<<"4.Salir. \n:.";
        cin >> opc;
        switch(opc){
        case 1:
            cout<<"Ingrese elemento: "; cin >> ele;
            pila->insertar(ele); break;
        case 2:
            pila->extraer(); break;
        case 3:
            pila->imprimir(); break;
        }
    }while (opc!=4);
}

int main(){
    Pila<char> *pila1;
    pila1 = new Pila<char>();

    menu(pila1);
    delete pila1;
    cin.get();
}
