#include <iostream>
#include <conio.h>

using namespace std;
//6.1
void imprime_array(int num[],const int tam){
    for (int i=0; i<tam; i++){
        cout<<num[i];
        if (i<tam-1){
            cout<<", ";
        }
    }
}

//6.2
void reverse_array(int num[],const int tam){
    for (int i=0; i<tam/2; i++){
        int aux,final_indice=tam-i-1;
        aux = num[i];
        num[i] = num[final_indice];
        num[final_indice] = aux;
    }
}

//6.3
const int LENGTH=10, WIDTH=10;
void transpose(const int input[][LENGTH], int output[][WIDTH]) {
    for(int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < LENGTH; ++j) {
            output[j][i] = input[i][j];
        }
    }
}
void llenar_matriz(int mat[][10],int f,int c){
    for(int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout<<"Numero: "; cin>>mat[i][j];
        }
    }
}
void mostrar_matriz(int mat[][10],int f,int c){
    for(int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//6.4
void transpose(const int input[][LENGTH]) {
    int output[][WIDTH];
    for(int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < LENGTH; ++j) {
            output[j][i] = input[i][j];
        }
    }
    void mostrar_matriz(output,WIDTH,LENGTH);
}

//6.5
void A_reverse(int num[], const int tam) {
    for (int i=0; i<tam/2; i++){
        int aux,final_indice=tam-i-1;
        aux = *(num+i);
        *(num+i) = *(num+final_indice);
        *(num+final_indice) = aux;
    }
}
int main()
{
    int nums[]={1,2,3,4,5};
    /*A_reverse(nums,5);
    imprime_array(nums,5);*/
    int entrada[10][10];
    int salida[10][10];
    llenar_matriz(entrada,3,4);
    mostrar_matriz(entrada,3,4);
    transpose(entrada);

    getch();
    return 0;
}
