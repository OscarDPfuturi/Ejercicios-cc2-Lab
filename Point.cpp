#include <iostream>

using namespace std;


//3 Point
class Point {
    int x, y;
public:
    Point(){x = 0; y = 0;}
    Point(int _x=0, int _y=0) {x = _x; y = _y;}
    int getX() const {return x;}
    int getY() const {return y;}
    void setX(const int _x) {x = _x;}
    void setY(const int _y) {y = _y;}
};
int main()
{
    Point P;
    P.setX(5);
    P.setY(3);
    cout<<P.getX()<<" "<<P.getY()<<endl;
}
