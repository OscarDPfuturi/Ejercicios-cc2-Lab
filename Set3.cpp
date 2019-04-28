#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//2
class Point{
private:
    int x, y;
public:
    //2.1
    Point(int u,int v) : x(u), y(v){}
    int getX() {return x;}
    int getY() {return y;}
    void doubleVal(){
        x *= 2;
        y *= 2;
    }
    //2.2
    void setX(int newX) { x=newX; }
    //2.4
    void setY(int newY);
};
//2.4
void Point::setY(int newY){y = newY; }

int main(){
    Point myPoint(5,3);
    myPoint.doubleVal();
    cout << myPoint.getX() << " " <<myPoint.getY()<<"\n";

    Point p(5,3);
    p.setX(900);
    cout<< p.getX() <<' '<< p.getY()<<endl;

    //2.3 acceder a los atributos por los metodos
    Point p1(5,4);
    //cout << p1.x <<' '<< p1.y <<endl;
    cout<< p1.getX() <<' '<< p1.getY()<<endl;
    //2.4
    p1.setY(0);
    cout<< p1.getX() <<' '<<p1.getY() <<endl;

    //2.5
    int size1;
    cin>>size1;
    int *nums = new int[size1];
    for (int i=0; i<size1; ++i){
        cin>>nums[i];
    }
    delete[] nums;//debe eliminar cada elemento del array dinamico

    //2.6
    Point *P = new Point(5,3);
    cout<< P->getX() <<' '<< P->getY();
    delete P;//debe eliminarse siempre el espacio de memoria reservado con new

    getch();
    return 0;
}
