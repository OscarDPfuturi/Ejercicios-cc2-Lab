#include <iostream>
#include <conio.h>

using namespace std;
//7.1
int conteo(char arr[]){
    int cont=0;
    while (arr[cont++] != '\n'){}
    return cont-1;
}
//7.2
void swap_num(int &a,int &b){
    int aux=a;
    a=b;
    b=aux;
}
//7.3
void swap_puntero(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}
//7.4
void swap_puntero_p(int **a,int **b){
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    char cad[]="Hola Mundo\n";
    cout<<conteo(cad)<<"\n";
    int a=5, b=8;
    int *c=&a, *d=&b;
    //c = &a; d = &b;
    swap_puntero_p(&c,&d);
    cout<<*c<<"\n"<<*d<<"\n";
    //7.5
    char *oddOreven = "Never odd or even";
    char *nthChar = &oddOreven[5];
    cout<<nthChar<<"\n";
    nthChar -= 2;
    cout<<*nthChar<<"\n";
    char **pointerPtr = &nthChar;
    cout<<pointerPtr<<"\n";
    cout<<**pointerPtr<<"\n";
    nthChar++;
    cout<<nthChar - oddOreven;
    getch();
    return 0;
}
