#include <iostream>
#include <cstdlib>

using namespace std;
//4.1
int suma(const int n1,const int n2){
    return n1 + n2;
}
double suma(const double n1,const double n2){
    return n1 + n2;
}

//4.3
/*int suma(const int n1,const int n2,const int n3){
    return n1+n2+n3;
}

int suma(const int n1,const int n2,const int n3,const int n4){
    return n1+n2+n3+n4;
}*/

//4.4
int suma(const int n1,const int n2,const int n3=0,const int n4=0){
    return n1+n2+n3+n4;
}

//4.5
/*int suma(int num[],const int len){
    int sum = 0,i;
    for (i=0; i<len; i++){
        sum +=num[i];
    }
    return sum;
}*/

//4.6
int suma(int num[],const int len){
    if (len == 1)
        return num[len-1];
    else
        return num[0] + suma(num+1,len-1);
}

int main()
{
    int num[10],n;
    cout<<"Tamanio array: "; cin>>n;
    for (int i=0; i<n; i++){
        cin>>num[i];
    }
    cout<<suma(num,n)<<"\n";
    return 0;
}
