#include <iostream>
#include <conio.h>

using namespace std;
//1
int suma_3_5(const int lim){
    int suma=0;
    for (int i=3; i<=lim; i++){
        if (i%3==0){
            suma += i;
        }
        else if (i%5==0 && i%15!=0){
            suma += i;
        }
    }
    return suma;
}

//2
int suma_fibonacci(int lim){
    int x=0, y=1, aux=0;
    long suma=0;

    while (true){
        aux = x+y;
        x = y;
        y = aux;
        suma += y;
        if (suma>lim){
            return y;//retorna el mayor nro fibonacci menor a lim
        }
    }
}
//3
bool esprimo(int numero){
    int i=2;
    if (numero==2){
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

int factores_primos(int num){
    int factores[10],k=0;
    for (int i=2; i<num/2; i++){
        while (num%i==0){
            num /= i;
        }
        if (esprimo(i))
            factores[k++]=i;
    }
}




//4numero palindromo
int palindromo(int digit){
    int p=0;
}

//5

int main(){
    int lim;
    cout<<"Numero: "; cin>>lim;
    //cout<<suma_3_5(lim)<<"\n";
    //cout<<suma_fibonacci(lim)<<"\n";
    cout<<esprimo(lim);

}
