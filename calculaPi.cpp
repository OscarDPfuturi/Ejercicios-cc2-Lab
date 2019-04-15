#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

//5.3
double calcula_Pi(const int n){
    int dartsInCircle = 0;
    for(int i= 0; i<n; ++i) {
        double x = rand() / (double) RAND_MAX, y = rand() / (double) RAND_MAX;
        if( sqrt(x*x + y*y) < 1 ) {
            ++dartsInCircle;
        }
    }
    return dartsInCircle/(double)(n)* 4;
}

int main()
{
    //5.1
    srand(time(0));
    //double x = ((double) rand()) / (double) RAND_MAX;
    //double y = rand() / (double) RAND_MAX;

    //5.2

    int n;
    cout<<"Numero lanzamientos: "; cin>>n;
    /*int dartsInCircle = 0;
    for(int i= 0; i<n; ++i) {
        double x = rand() / (double) RAND_MAX, y = rand() / (double )RAND_MAX;
        if( sqrt(x*x + y*y) < 1 ) {
            ++dartsInCircle;
        }
    }
    cout<<dartsInCircle<<"\n";*/
    cout<<calcula_Pi(n);
    return 0;
}
