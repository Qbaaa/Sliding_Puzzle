#ifndef NUMBERPUZZLE_H
#define NUMBERPUZZLE_H

template <typename T>
class Point;

/**
* Klasa NumberPuzzle jest przeznaczona do modelowania klockow (pól) na planszy SquareBoard
*
* Zadaniem klasy jest przechowywanie ponumerowanego pola oraz punktu, który reprezentuje
* współrzędne x i y, który określa miejsce znajdywania się danego kolcka(pola) na planszy
*/
class NumberPuzzle{

private:
    /**
    * Pole number przechowuje liczbę, która określa numer danego kolcka (pola) w grze
    */
    int number;

    /**
    * Pole point przechowuje adres do współrzędnych x i y, który określa miejsce znajdywania się
    * danego kolcka(pola) na planszy
    */
    Point<int> *point;

public:
    /**
    * Konstruktor bezargumentowy, który tworzy klocek (pole). Ustawia atrybuty klasy domyślnimi wartościami
    */
    NumberPuzzle();

    /**
    * Konstruktor argumentowy, który tworzy klocek (pole). Ustawia atrybuty klasy podanymi wartościami
    *
    * @param _number - wartość numeru klocka(pola)
    * @param _point - adres współrzędnych x i y klocka (pola)
    */
    NumberPuzzle(int _number, Point<int> *_point);

    /**
    * Konstruktor kopiujący, który służy do stworzenia nowego klocka (pola) poprzez skopiowanie atrybutów od innego klocka (pola)
    *
    * @param _numberPuzzle - wartość innego klocka (pola), który ma zostac skopiowany
    */
    NumberPuzzle(const NumberPuzzle& _numberPuzzle);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~NumberPuzzle();

    /**
     * Funkcja udostępnia numer przechowywanego klocka (pola)
    *
    * @return zwraca numer danego klocka (pola), przechowywanego w danej klasie
    */
    int getNumber() const;

    /**
    * Funkcja udostępnia wspólrzędne przechowywanego klocka(pola)
    *
    * @return zwraca współrzędne danego klocka (pola), przechowywanego w danej klasie
    */
    Point<int>* getPoint() const;

    /**
    * Funkcja słuzy do zmiany numeru przechowywanego klocka(pola)
    *
    * @param _number - nowa wartość numeru klocka (pola)
    */
    void setNumber(int _number);

    /**
    * Funkcja słuzy do zmiany współrzędnych przechowywanego klocka(pola)
    *
    * @param _point - nowy adres wspólrzędnych klocka (pola)
    */
    void setPoint(Point<int> *_point);

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje klasa
    */
    void toString();

};

#endif // NUMBERPUZZLE_H
