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
class Cola{//////////////////////////////////clase Cola///////////////////////////////////
    Nodo<T> *adelante;
    Nodo<T> *atras;
    int cont;
public:
    Cola(){adelante = NULL; atras = NULL; cont = 0;};
    ~Cola();

    void insertar(T);
    void extraer();
    void imprimir();
    bool esta_vacio();



};


template<class T>
bool Cola<T>::esta_vacio(){
    return(cont == 0);
}

template<class T>
void Cola<T>::insertar(T data){
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->set_dato(data);
    nuevo->set_nodo(NULL);
    if(esta_vacio()){
        adelante = nuevo;
    }
    else{
        atras->set_nodo(nuevo);
    }
    atras = nuevo;
    cont++;
}

template<class T>
void Cola<T>::extraer(){
    if(esta_vacio()){
        cout << "Esta vacio" << endl;
    }
    else{
        Nodo<T> *temp = adelante;
        if(adelante == atras){
            adelante = NULL;
            atras = NULL;
        }
        else{
            adelante = adelante->get_nodo();
        }
        delete temp;
        cont--;
    }
}


template <typename T>
void Cola<T>::imprimir(){
    Nodo<T> *reco = adelante;
    cout << "Elementos en la cola.\n";
    while (reco != NULL){
        cout << reco->get_dato() << "-";
        reco = reco->get_nodo();
    }
    cout << "\n";
}

template <typename T>
Cola<T>::~Cola(){
    Nodo<T> *reco = adelante;
    Nodo<T> *bor;
    while (reco != NULL){
        bor = reco;
        reco = reco->get_nodo();
        delete bor;
    }
}



template <typename T>
void menu(Cola<T> *cola){
    int opc;
    T ele;
    do {
        cout<<"Elija una opción: "<<endl;
        cout<<"1.Insertar elemento. "<<endl;
        cout<<"2.Extraer elemento. "<<endl;

        cout<<"3.Mostrar contenido. "<<endl;
        cout<<"4.Salir. \n:.";
        cin >> opc;
        switch(opc){
        case 1:
            cout<<"Ingrese elemento: "; cin >> ele;
            cola->insertar(ele); break;
        case 2:
            cola->extraer(); break;
        case 3:
            cola->imprimir(); break;
        }
    }while (opc!=4);
}

int main(){
    Cola<int> *cola1;
    cola1 = new Cola<int>();

    menu(cola1);
    delete cola1;
    cin.get();
}
