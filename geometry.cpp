#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "geometry.h" //header

using namespace std;

//4
PointArray::PointArray() {
    size = 0;
    points = new Point[0];
}

PointArray::PointArray( const Point _pts[], const int _size){
    size = _size;
    points = new Point[_size];
    for(int i = 0; i < _size; ++i) {
        points[i] = _pts[i];
    }
}

PointArray::PointArray( const PointArray &p) {
    size = p.size;
    points = new Point[size];
    for (int i=0; i<size; i++) {
        points[i] = p.points[i];
    }
}

PointArray::~PointArray(){
    delete[] points;
}

void PointArray::resize( int _Size) {
    Point *pts = new Point[_Size];
    int minSize = (_Size > size ? size : _Size);
    for (int i = 0; i < minSize; i++)
        pts[i] = points[i];
    delete [] points;
    size = _Size;
    points = pts;
}

void PointArray::clear() {
    resize(0);
}

void PointArray::push_back(const Point &p){
    resize(size + 1);
    points[size - 1] = p;
}

void PointArray::insert( const int pos, const Point &p) {
    resize(size + 1);

    for (int i= size -1; i>pos; i--) {
        points[i] = points[i -1];
    }
    points[pos] = p;
}

void PointArray::remove( const int pos) {
    if(pos >= 0 && pos < size) {
        for(int i = pos; i < size -2; i++) {
            points[i] = points[i + 1];
        }
        resize(size -1);
    }
}

Point *PointArray::get( const int pos) {
    return pos >= 0 && pos < size ? points + pos : NULL;
}

const Point *PointArray::get( const int pos) const {
    return pos >= 0 && pos < size ? points + pos : NULL;
}

//5.123
int Polygon::numPolygons = 0;

Polygon::Polygon(const PointArray &pa) : points(pa){
    ++numPolygons;
}
Polygon::Polygon(const Point pointArr[],const int numPoints) : points(pointArr, numPoints){
    ++numPolygons;
}

//5.4
Point constructorPoints[4];
Point *updateConstructorPoints(const Point &p1,const Point &p2,const Point &p3, const Point &p4 = Point(0,0)) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

Rectangle::Rectangle( const Point &ii, const Point &sd) :
    Polygon(updateConstructorPoints(ii, Point(ii.getX(), sd.getY()), sd, Point(sd.getX(), ii.getY())), 4) {}

Rectangle::Rectangle( const int x1, const int y1, const int x2, const int y2) :
    Polygon(updateConstructorPoints(Point(x1, y1), Point(x1, y2), Point(x2, y2), Point(x2, y1)), 4) {}

double Rectangle::area() const {
    int length = points.get(1)->getY() - points.get(0)->getY();
    int width = points.get(2)->getX() - points.get(1)->getX();
    return abs(( double )length * width);
}

//5.5
Triangle::Triangle( const Point &a, const Point &b, const Point &c) :
    Polygon(updateConstructorPoints(a, b, c), 3) {}

double Triangle::area() const {
    int dx01 = points.get(0) ->getX() - points.get(1) ->getX(),
        dx12 = points.get(1) ->getX() - points.get(2) ->getX(),
        dx20 = points.get(2) ->getX() - points.get(0) ->getX();
    int dy01 = points.get(0) ->getY() - points.get(1) ->getY(),
        dy12 = points.get(1) ->getY() - points.get(2) ->getY(),
        dy20 = points.get(2) ->getY() - points.get(0) ->getY();

    double a = sqrt(dx01*dx01 + dy01*dy01),
        b = sqrt(dx12*dx12 + dy12*dy12),
        c = sqrt(dx20*dx20 + dy20*dy20);

    double s = (a+b+c) /2;

    return sqrt( s * (s-a) * (s-b) * (s-c) );
}

void printAttributes(Polygon *p) {
    cout << "El area es " << p->area() << ".\n";
    cout << "Los puntos son:\n";
    const PointArray *pa = p->getPoints();
    for(int i = 0; i < pa->getSize(); ++i) {
        cout <<"("<< pa->get(i) ->getX() <<", "<< pa->get(i)->getY() <<")\n";
    }
}

int main(){
    cout<<"Coordenadas (a,b) y (c,d) debe ingresar: a b c d" <<endl;
    cout <<"Ingrese las coordenadas inferior izquierda y superior derecha del rectangulo: "<<endl;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point ii(x1, y1), sd(x2, y2);
    Rectangle r(ii, sd);
    printAttributes(&r);

    cout << "Ingrese 3 coordenadas:"<<endl;
    int X1, Y1, X2, Y2, X3, Y3;
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    Point a(X1, Y1), b(X2, Y2), c(X3, Y3);
    Triangle t(a, b, c);
    printAttributes(&t);
    getch();
    return 0;
}
