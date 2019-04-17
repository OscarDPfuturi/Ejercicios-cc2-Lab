#include <iostream>
#include <stdlib.h>
#include <math.h>
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
    int x=1, y=2, z=0;
    long suma=3;

    while (true){
        z = x+y;
        x = y;
        y = z;
        if (y>lim){
            cout<<x<<"\n";
            return suma;//
        }
        suma += y;
    }
}
//3
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
void imprime(long int num[],int t){
    for (int i=0; i<t; i++){
        cout<<num[i]<<" ";
    }
}

void factores_primos(const long int num){
    long factores[100]={0};
    int k=0,aux=num,j=0;
    if (!esprimo(num)){
        for (int i=2; i<=num/2; i++){
            while (aux%i==0){
                aux /= i;
                if (factores[0]==0){//llena el primer elemento con el primer factor primo
                    factores[k++]=i;
                }
                else if (i!=factores[j]){//compara i no sea igual al anterior factor primo
                    factores[k++]=i;     //para evitar repeticiones
                    j++;
                }
            }
        }
    }
    imprime(factores,k);
}

//4numero palindromo
int contar_digitos(int num){
    int cont=0;
    while(num>=1){
        num /= 10;
        cont++;
    }
    return cont;
}
bool es_palindromo(int num){
    int digitos=contar_digitos(num);
    int num2=0,aux=num;
    for (int i=0; i<=digitos; i++){
        if (aux>=10){
            num2 += floor(aux%10);
        }

        else {
            num2 += aux;
        }
        num2 *= 10;
        if (num2==num*10){
            return 1;
        }
        aux = aux/10;
    }
    return 0;
}
int mayor_palindromo(int digit){
    int j=pow(10,digit-1), i=pow(10,digit-1);
    int aux = i*j;
    while (j<pow(10,digit)){
        if (es_palindromo(j*i)==1 && j*i>pow(10,2*digit)){
            return aux;
        }
        aux = j*i;
        if (i==pow(10,digit)-1){
            j++;
        }
        else {
            i++;
        }
    }
    return 0;
}

//5
int smallest_num(int lim){
    int aux=lim,k=0;
    while(k!=aux){
        k = 0;
        while (lim%(k+1)==0){
            k++;
        }
        lim++;
    }
    return --lim;

}

//6
int dif_square(int num){
    int suma1=0,suma2=0;
    for (int i=1; i<=num; i++){
        suma1 += pow(i,2);
    }
    for (int j=1; j<=num; j++){
        suma2 += j;
    }
    suma2 = pow(suma2,2);
    return suma2 - suma1 + 1;
}

//7
int n_primo(int num){
    int cont=0,i=2;
    while(cont != num){
        if (esprimo(i)){
            cont++;
        }
        i++;
    }
    return --i;
}

int main(){
    unsigned int lim;
    cout<<"Numero: "; cin>>lim;
    //cout<<suma_3_5(lim)<<"\n";
    //cout<<suma_fibonacci(lim)<<"\n";
    //factores_primos(lim);
    //cout<<smallest_num(lim);
    //cout<<mayor_palindromo(lim);
    //cout<<dif_square(lim);
    cout<<n_primo(lim);
    getch();
    return 0;
}
