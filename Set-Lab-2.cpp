#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
//3.1
//void printNum(int);
void printNUm(const int num){
    cout<<num<<endl;
}
//3.2
void printN(int num){
    cout << num<<endl;
}
//3.3 paso por referencia
void doubleNum(int &num){
    num = num * 2;
}
//3.4
int diferencia(const int a, const int b){
    int dif = abs(a - b);
    return dif; //retorna un entero
}
//3.5
int sum(const int x,const int y,const int z){
    return x+y+z;
}
//3.6
const int ARRAY_LEN = 10;

//7.1
int length_array(char *arr){
    int cont = 0;
    while (*(arr+cont)!='\0');{
        ++cont;
    }
    return cont;
}
//7.2
void swap_nums(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}
//7.3
void swap_point(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
//7.4
void swap3(int **x, int **y) {
    int *tmp = *x;
    *x = *y;
    *y = tmp;
}
int main(){
    //3.3
    int n = 35;
    int &m = n;
    doubleNum(m);
    cout<<n<<endl;
    //3.6
    int arr[ARRAY_LEN] = {10};//primer elemento = 10

    int *xPtr = arr, *yPtr = arr + ARRAY_LEN - 1;
    cout<<*xPtr<<' '<<*yPtr; // 10 0

    //7.4
    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    swap3(&ptr1,&ptr2);
    cout<<*ptr1<<' '<<*ptr2; // 6 5

    //7.5
    char *oddOrEven = "Never odd or even ";
    char *nthCharPtr = &oddOrEven[5];
    nthCharPtr -= 2; //tambien puede usarse nthCharPtr = oddOrEven + 3;
    cout << *nthCharPtr;
    char **pointerPtr = &nthCharPtr;
    cout << pointerPtr;
    cout << **pointerPtr;
    nthCharPtr++; //apunta a la siguiente posicion del array
    cout << nthCharPtr -oddOrEven;

    getch();
    return 0;
}
