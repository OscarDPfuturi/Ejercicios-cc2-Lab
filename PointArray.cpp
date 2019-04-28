#include <iostream>
#include <conio.h>
#include "geometry.h" //header

using namespace std;

//4.1
class PointArray {
    int size;
    Point *points;
    void resize(int size);
public:
    PointArray();
    PointArray(const Point pts[],const int size);
    PointArray( const PointArray &pv);
    ~PointArray();
    void clear();
    int getSize() const { return size;}
    void push_back( const Point &p);
    void insert( const int pos, const Point &p);
    void remove( const int pos);
    Point *get( const int pos);
    const Point *get( const int pos) const ;
};

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

