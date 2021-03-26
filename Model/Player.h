#ifndef PLAYER_H
#define PLAYER_H

#include "NumberPuzzle.h"

#include <vector>
using namespace std;

/**
* Klasa abstrakcyjna Player jest przeznaczona do bycia podstawą dla innych klas,
* które bedą dziedziczyc po niej zachowania
*
* Zadaniem klasy jest przechowywanie ilość wykonanych ruchów
*/
class Player {

protected: 
    /**
    * Pole moves przechowuje liczbę, która określa ilość wykonanych przesunieć pól przez gracza
    */
    int moves;

public:
    /**
    * Konstruktor bezargumentowy, który ustawia pole moves domyślna wartością 0
    */
    Player();

    /**
    * Konstruktor argumentowy, który ustawia pole moves podaną wartością
    *
    * @param _moves - ilość wykonanych ruchów przez gracza
    */
    Player(int _moves);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    virtual ~Player();

    /**
    * Funkcja udostępnia ilość wykonanych przesunieć pól przez gracza
    *
    * @return liczba określająca ilość wykonanych przesunieć pól przez gracza
    */
    int getMoves() const;

    /**
    * Funkcja słuzy do zmiany ilość wykonanych przesunieć pól przez gracza
    *
    * @param _moves - nowa liczba określająca ilość wykonanych przesunieć pól przez gracza
    */
    void setMoves(int _moves);

    /**
    * Funkcja słuzy do zwiększenia o jeden pola moves
    */
    void increaseOneMoves();

    /**
    * Funkcja słuzy do wykonania ruchu przez danego gracza
    *
    * @param gameSquareBoard - kwadratowa plansza przechowywującą numery pól wraz z
    *                          współrzędnymi danych pól
    *
    * @return obiekt pola wybranego przez gracza, którym chce się poruszyć
    */
    virtual NumberPuzzle* move(vector<vector<NumberPuzzle>> gameSquareBoard, int moveNumberPuzzle) = 0;

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje klasa
    */
    virtual void toString() = 0;
};

#endif // PLAYER_H
