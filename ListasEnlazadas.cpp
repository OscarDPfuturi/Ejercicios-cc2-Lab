#include <iostream>
#include <stdio.h>

#include "list.h"
#include "list.cpp"

using namespace std;

int main()
{
    List<int> list_1;
    List<char> list_2;
    char c;
    int ele;

    int dim;
    //int pos;
    //string file_with_list;
    cout << "Ingresa la dimensión de la lista: " << endl;
    cin >> dim;
    for (int i=0; i<dim; i++){
        //fflush(stdin);
        cout<<"ingrese elemento: "; cin>>c;
        list_2.add_head(ele);

    }
    list_2.print();


    list_1.fill_random(dim);

    cout << "Lista: " << endl;
    list_1.print();

    cout << "Agrega un elemento (cabeza): " << endl;
    cin >> ele;
    list_1.add_head(ele); //agrega al inicio...
    list_1.print();

    cout << "Lista invertida: " << endl;
    list_1.invertir();
    list_1.print();

    cout << "Lista ordenada: " << endl;
    list_1.sort();
    list_1.print();

    cout << "Agrega un elemento. Será insertado ordenadamente: " << endl;
    cin >> ele;
    list_1.add_sort(ele);
    list_1.print();
    return 0;
}
