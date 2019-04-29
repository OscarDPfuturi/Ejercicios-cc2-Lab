#include <iostream>
#include <conio.h>

using namespace std;
//2.1
template <class T>
T menor(const T num1,const T num2){
    return (num1 < num2) ? num1 : num2;
}
//2.2
#define min(x, y) (x < y ? x : y)

int main(){
    int a = 5;
    int b = 8;
    cout<<menor<int>(a,b)<<endl;
    cout<<min<int>(3,5)<<endl;
    getch();
    return 0;
}
