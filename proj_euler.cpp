#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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
    long suma=0;

    while (x<lim){
        if (x%2==0){
            suma += x;
        }
        z = x+y;
        x = y;
        y = z;
        /*if (y>lim){
            cout<<x<<"\n";//numero fibonacci maximo menor a lim
            return suma+3;//suma de la secuencia hasta x
        }*/
    }
    return suma;
}
//3
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
void imprime(long int num[],int t){
    for (int i=0; i<t; i++){
        cout<<num[i]<<" ";
    }
}

int factores_primos(const long int num){
    long factores[10]={0};
    long k=0,aux=num,mayor_primo=0;
    if (!esprimo(num)){
        for (long i=2; i*i<num; i++){
            if (aux%i==0){
                aux /= i;
                if (esprimo(i)){
                    factores[k++]=i;
                    mayor_primo = i;
                }
            }
        }
    }
    imprime(factores,k);
    cout<<"\n";
    return mayor_primo;
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
    if (num%10==0){
        return 0;
    }
    int digitos=contar_digitos(num);
    int aux=num;
    int mult_diez=pow(10,digitos-1);
    int num_der = aux%10;
    int num_izq = floor(aux/mult_diez);
    while (num_der == num_izq){

        aux -= num_izq*mult_diez;
        if (aux <= mult_diez/10){
            aux -= num_der;
        }
        else {
            aux -= num_der;
            aux /= 10;
        }
        mult_diez /= 100;
        if (aux<10){
            return 1;
        }
        num_der = aux%10;
        num_izq = floor(aux/mult_diez);
    }
    return 0;
}

int mayor_palindromo(int digitos){
    int j=pow(10,digitos-1), i=j;
    int aux = i*j,mayor;
    int mult_diez=pow(10,digitos);
    while (j<mult_diez+1){
        if (es_palindromo(aux)){
            mayor = aux;
        }
        if (i==mult_diez-1){
            j++;
            i=mult_diez/10;
        }
        else {
            i++;
        }
        aux = j*i;
    }
    return mayor;
}

//5
long smallest_num(int lim){
    unsigned long aux=lim;
    int k=2;
    while(k!=lim+1){
        k = 2;
        while (aux%(k)==0){
            k++;
        }
        aux++;
    }
    return --aux;
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

//8

//9
int prod_abc(int num_suma){
    int a=1,b=1,c=1;
    while (a<num_suma && sqrt(c)+b+a!=num_suma){
        if (b==num_suma){
            a++;
            b=1;
        }
        b++;
        c = a*a + b*b;
    }
    c = sqrt(c);
    return a*b*c;
}

int main(){
    unsigned long lim;
    cout<<"Numero: "; cin>>lim;
    //cout<<suma_3_5(lim)<<"\n";
    //cout<<suma_fibonacci(lim)<<"\n";
    //cout<<factores_primos(lim)<<endl;
    //cout<<smallest_num(lim);
    //cout<<es_palindromo(lim)<<endl;
    //cout<<mayor_palindromo(lim);
    //cout<<dif_square(lim);
    //cout<<n_primo(lim);
    //cout<<prod_abc(lim);

    getch();
    return 0;
}
