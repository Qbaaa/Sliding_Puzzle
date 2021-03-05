#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

/**
* Szablon klasy Point jest przeznaczony do modelowania Punktu, który przechowuje współrzędne X i Y w
* układzie współrzędnych
*
* Zadaniem szablonu klasy jest przechowywanie dwóch wartości, które reprezentują współrzędną X i Y
*
* @tparam T Dowolny typ całkowity, taki jak int, long, long long lub typ zmiennoprzecinkowy, taki jak float, double lub long double
*/
template<typename T>
class Point{

private:
    /**
    * Pole x przechowuje liczbę, która określa współrzędną x
    */
    T x;

    /**
    * Pole y przechowuje liczbę, która określa współrzędną y
    */
    T y;

public:
    /**
    * Konstruktor bezargumentowy, który tworzy punkt. Ustawia atrybuty szablonu klasy domyślnimi wartościami
    */
    Point();

    /**
    * Konstruktor argumentowy, który punkt. Ustawia atrybuty klasy podanymi wartościami
    *
    * @param _x - wartość współrzędnej X
    * @param _y - wartość współrzędnej Y
    */
    Point(T _x, T _y);

    /**
    * Konstruktor kopiujący, który służy do stworzenia nowego punktu poprzez skopiowanie atrybutów od innego punktu
    *
    * @param _point - wartość innego punktu, który ma zostac skopiowany
    */
    Point(const Point& _point);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~Point();

    /**
    * Funkcja udostępnia współrzędną X w przechowyanym punkcie
    *
    * @return wartość współrzędnej X dla danego punktu
    */
    T getX() const;

    /**
    * Funkcja udostępnia współrzędną Y w przechowyanym punkcie
    *
    * @return wartość współrzędnej Y dla danego punktu
    */
    T getY() const;

    /**
    * Funkcja słuzy do zmiany współrzędnej X w przechowywanym punkcie
    *
    * @param _x - nowa wartość współrzędnej X dla danego punktu
    */
    void setX(T _x);

    /**
    * Funkcja słuzy do zmiany współrzędnej Y w przechowywanym punkcie
    *
    * @param _x - nowa wartość współrzędnej Y dla danego punktu
    */
    void setY(T _y);

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje szablon klasy
    */
    void toString();
};

template<typename T>
Point<T>::Point(): x(0), y(0) {}

template<typename T>
Point<T>::Point(T _x, T _y): x(_x), y(_y){}

template<typename T>
Point<T>::Point(const Point& _point): x(_point.getX()), y(_point.getY()) {}

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

template<typename T>
void Point<T>::toString()
{
    cout << "Point { ";
    cout << "x: " << x;
    cout << ", y: " << y;
    cout << " }";
}

#endif // POINT_H
