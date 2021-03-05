#ifndef PERSON_H
#define PERSON_H

#include "Player.h"

/**
* Klasa Person jest przeznaczona do modelowania osoby, która ręcznie będie grała w grę
*/
class Person: public Player {

public:
    /**
    * Konstruktor bezargumentowy, który ustawia pole moves z klasy dziedziczącej domyślna wartością 0
    */
    Person();

    /**
    * Konstruktor argumentowy, który ustawia pole moves z klasy dziedziczącej podaną wartością
    *
    * @param _moves - ilość wykonanych ruchów przez gracza
    */
    Person(int _moves);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~Person();

    /**
    * Funkcja słuzy do wykonania ręcznego ruchu przez użytkownika
    *
    * @param gameSquareBoard - kwadratowa plansza przechowywującą numery pól wraz z
    *                          współrzędnymi danych pól
    *
    * @return obiekt pola wybranego przez użytkownika, którym chce się poruszyć
    */
    NumberPuzzle* move(vector<vector<NumberPuzzle>> gameSquareBoard);

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje klasa
    */
    void toString();
};

#endif // PERSON_H
