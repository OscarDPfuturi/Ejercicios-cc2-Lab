#include <iostream>
#include <conio.h>

using namespace std;

bool esprimo(long numero){

    if (numero < 2 || numero%10==0 || numero%4==0 || numero%6==0){
        return 0;
    }
    if(numero == 2){
        return 1;
    }
    long i=2;
    int aux=numero/2;
    while (i<=aux){
        if (numero%i==0){
            return 0;
        }
        ++i;
    }
    return 1;
}

int main(){
    //2 HELLO WORLD!
    const char *cad = "Hola Mundo!";
    cout<<cad<<endl;
    const int n=3;
    cout<<"\n";
    int i=0;
    for (; i++<n;){
        cout<<cad<<endl;
    }
    cout<<"\n";
    i=0;
    while (i++<n){
        cout<<cad<<endl;
    }
    cout<<"\n";
    i=0;
    do{
        cout<<cad<<endl;
    }while (++i<n);

    //3.2 Estadística básica
    int N;
    double lista[10];
    double mean = 0;
    int mayor = 0, menor = 999;
    cout<<"Tamanio de la lista: "; cin>>N;
    for (int i=0; i<N; i++){
        cout<<"Numero: "; cin>>lista[i];
        mean += lista[i];
        if (lista[i]>mayor){
            mayor = lista[i];
        }
        if (lista[i]<menor){
            menor = lista[i];
        }
    }
    mean /= N;
    cout<<"Media: "<<mean<<"\n";
    cout<<"Mayor valor: "<<mayor<<"\n";
    cout<<"Menor valor: "<<menor<<"\n";
    cout<<"Rango: "<<mayor - menor<<"\n";
    //3.3
    int num,cont=0,i=2;
    int list_primos[20];
    cout<<"Ingrese un numero: "; cin>>num;
    while (cont!=num){
        if (esprimo(i)){
            list_primos[cont]=i;
            cont++;
        }
        i++;
    }
    for (int j=0; j<num; j++){
        cout<<list_primos[j]<<" ";
    }
    //3.4.1
    int N;

    while(true){
        cout<<"Numero: "; cin>>N;
        cout<< ((N%5==0 && N>0) ? N/5 : -1) <<endl;
    }
    //3.4.2
    int N;
    while(true){
        cout<<"Numero: "; cin>>N;
        if (N%5!=0){
            continue;
        }
        cout<<N/5<<endl;
    }
    //3.4.3
    int N;
    while(true){
        cout<<"Numero: "; cin>>N;
        if (N < 0){
            cout<<"Good Bye!"<<endl;
            break;
        }
        if (N%5!=0){
            continue;
        }
        cout<<N/5<<endl;
    }
    //4.2
    short num;
    cout << "Numero: ";
    cin >> num;
    if (num>=0){
        cout << "EL factorial de " << num << " es ";
        long int fact = 1;
        for (; num > 0; fact *= num--);
        cout << fact << ".\n";
    }
    else {
        cout<<"El numero es Negativo."<<endl;
    }
    //4.4
    int num;
    cout << "Numero: ";
    cin >> num;
    if(num < 0){
        cout << "No se permiten numeros negativos\n";
        return 1;
    }
    if(num > 20){
        cout << "El programa no dara un resultado correcto\n";
    }
    unsigned long int fact = 1;
    cout << "El factorial de " << num << " es ";
    for (; num > 0; fact *= num--);
    cout<< fact << ".\n";

    //4.5
    int num ;
    cout<<"Numero: ";
    cin>>num ;
    switch (num){
        case 0:
        case 1: cout<<"1\n"; break;
        case 2: cout<<"2\n"; break;
        case 3: cout<<"6\n"; break;
        case 4: cout<<"24\n"; break;
        case 5: cout<<"120\n"; break;
        case 6: cout<<"720\n"; break;
        case 7: cout<<"5040\n"; break;
        case 8: cout<<"40320\n"; break;
        case 9: cout<<"362880\n"; break;
        case 10: cout<<"3628800\n"; break;
        default: cout<<"Numero no permitido.\n"; break;
    }
    getch();
    return 0;
}
