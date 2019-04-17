#include <iostream>

using namespace std;

bool esprimo(int numero){
    int i=2;
    if (numero < 2){
        return 0;
    }
    if(numero == 2){
        return 1;
    }
    while (i<numero){
        if (numero%i==0){
            return 0;
        }
        ++i;
    }
    return 1;
}

//10
long int suma_primos(int num){
    unsigned long int suma=0;
    int i=2;
    while (i<num){
        if (esprimo(i)){
            suma += i;
        }
        i++;
    }
    return suma;
}

int main()
{
    int num;
    cout<<"Numero: "; cin>>num;
    cout<<suma_primos(num);
    return 0;
}
