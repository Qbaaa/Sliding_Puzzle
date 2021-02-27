#ifndef POINT_H
#define POINT_H

template<typename T>
class Point{

private:
    T x;
    T y;

public:
    Point();
    Point(T _x, T _y);
    Point(Point& _point);
    ~Point();
    T getX() const;
    T getY() const;
    void setX(T _x);
    void setY(T _y);
};

template<typename T>
Point<T>::Point(): x(0), y(0){}

template<typename T>
Point<T>::Point(T _x, T _y): x(_x), y(_y){}

template<typename T>
Point<T>::Point(Point& _point): x(_point.getX()), y(_point.getY()){}

template<typename T>
Point<T>::~Point() {}

template<typename T>
T Point<T>::getX() const
{
    return x;
}

template<typename T>
T Point<T>::getY() const
{
    return y;
}

template<typename T>
void Point<T>::setX(T _x)
{
    x = _x;
}

template<typename T>
void Point<T>::setY(T _y)
{
    y = _y;
}


#endif // POINT_H
