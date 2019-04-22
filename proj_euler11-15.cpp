#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <fstream>

using namespace std;

int conteo(long num){
    int cont=0;
    while (num>=1){
        cont++;
        num /= 10;
    }
    return cont;
}

//11

//12
long tri_numbers(const int Ndivisores){
    long n = Ndivisores,aux;
    int cont=0;//contará la cantidad de divisores de aux
    while (true){
        aux = n*(n+1)/2;//la sumatoria de 1 hasta n
        for (int i=1; i<=aux; i++){
            if (aux%i==0){
                cont++;
            }
        }
        if (cont>Ndivisores){//comprueba que cont sea mayor a la cantidad
            return aux;     //de divisores ingresados
        }
        n++;
        cont=0;
    }
    return 0;
}

//13
float suma_10digits(char cad[]){
    float suma=0;
    for (int i=0; i<100; i++){
        float num = atof(cad)
        suma += num;
    }
    while (conteo(suma)>10){
        suma /= 10;
    }
    return suma;
}
void lectura(){
    ifstream archivo;
    string cad;
    archivo.open("d:\\numeros.txt",ios::in);
    if (archivo.fail()){
        cout<<"No existe el archivo"<<endl;
        exit(1);
    }
    while (!archivo.eof()){
        getline(archivo,cad);
        cout<<cad<<endl;
    }
}

//14
int longest_Collatz(const int num){
    int n=num/2,result;
    int mayor_cad=0;
    while (n<=num){
        int aux = n;
        int cont = 1;
        while (aux!=1){
            if (aux%2==0){
                aux /= 2;
            }
            else {
                aux = aux*3+1;
            }
            cont++;
        }
        if (cont>mayor_cad){
            mayor_cad = cont;
            result = n;
        }
        n++;
    }
    return result;
}

//15
long pasos_grilla(const int n_grilla){//https://www.mathblog.dk/
    long pasos = 1;

    for (int i = 0; i < n_grilla; i++) {
        pasos *= (2*n_grilla - i);
        pasos /= (i + 1);
    }
    return pasos;
}



int main(){
    unsigned int lim;
    //char cad[]="3710.728753";
    cout<<"Numero: "; cin>>lim;
    cout<<tri_numbers(lim);
    //cout<<suma_10digits(cad);

    //lectura();
    //cout<<longest_Collatz(lim);
    //cout<<pasos_grilla(lim);
    getch();
    return 0;
}
