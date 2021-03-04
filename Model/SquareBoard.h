#ifndef SQUAREBOARD_H
#define SQUAREBOARD_H

#include <list>
#include <vector>
class NumberPuzzle;

using namespace std;

/**
* Klasa SquareBoard jest przeznaczona do modelowania kwadratowej planszy przechowywującej klasy NumberPuzzle
*
* Zadaniem klasy jest przechowywanie rozmiaru kwadratowej planszy,
* tablicy numerów dla planszy(początkowy stan rozmieszczenia numerów) oraz
* dwuwymiarową tablicę, która przedstawia kwadratową planszę
*/
class SquareBoard{

private:
    /**
    * Pole size przechowuje liczbę, która określa rozmiar kwadratowej planszy w grze
    */
    int size;

    /**
    * Pole startNumbersPuzzle przechowuje tablice numerów dla początkowego stanu gry
    */
    vector<int> startNumbersPuzzle;

    /**
    * Pole gameNumbersPuzzle przechowuje dwuwymiarową tablicę, która reprezentuje
    * kwadratową planszę przechowywującą numery pól wraz z współrzędnymi danego pola
    */
    vector<vector<NumberPuzzle>> gameNumbersPuzzle;

    /**
    * Funkcja służy do wspomagania konstruktorów. Ustawia pole size podaną wartością oraz
    * tworzy kwadratową planszę z wylosowanymi numerami
    *
    * @param _size - rozmiar kwadratowej planszy
    */
    void initSquareBoard(int _size);

public:
    /**
    * Konstruktor bezargumentowy, który tworzy kwadratową plansze. Ustawia atrybuty klasy domyślnimi wartościami
    *
    * Konstruktor ustawia pole size domyślna wartością 2 oraz tworzy kwadratową planszę z wylosowanymi numerami
    */
    SquareBoard();

    /**
    * Konstruktor argumentowy, który tworzy kwadratową plansze. Ustawia atrybuty klasy podaną wartością
    *
    * Konstruktor ustawia pole size podaną wartością oraz tworzy kwadratową planszę z wylosowanymi numerami
    *
    * @param _size - rozmiar kwadratowej planszy
    */
    SquareBoard(int _size);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~SquareBoard();

    /**
     * Funkcja udostępnia rozmiar kwadratowej planszy
    *
    * @return rozmiar kwadratowej planszy
    */
    int getSize() const;

    /**
     * Funkcja udostępnia tablicę dwuwymiarową, która reprezentuję planszę kwadratową przechowuje numery pól wraz z współrzednumi
    *
    * @return tablica dwuwymiarowa, reprezentuję planszę kwadratową
    */
    vector<vector<NumberPuzzle>> getGameNumberPuzzle() const;

    /**
     * Funkcja udostępnia tablice numerów dla początkowego stanu gry
    *
    * @return tablice numerów dla początkowego stanu gry
    */
    vector<int> getStartNumberPuzzle() const;

    /**
    * Funkcja słuzy do zmiany rozmiaru kwadratowej planszy oraz wylosowaniu nowych liczb dla planszy
    *
    * @param _size - nowy rozmiar kwadratowej planszy
    */
    void setSizeAndStartAndGameNumberPuzzle(int _size);

    /** 
    * Funkcja służy do losowania numerów pól dla kwadratowej planszy
    *
    * @param sizeSquareBoard - rozmiar kwadratowej planszy
    *
    * @return tablica numerów wylosowany dla kwadratowej planszy
    */
    vector<int> randomNumbersPuzzle(int sizeSquareBoard);

    /**
    * Funkcja służy do sprawdzania czy plansza z podanymi numerami jest mozliwa do rozwiązania
    *
    * @param numbersPuzzleForSquareBoard - tablica numerów, które mają być rozmieszczone na planszy
    *
    * @param sizeSquareBoard - rozmiar kwadratowej planszy
    *
    * @return true - plansza z podanymi numerami jest możliwa do rozwiązania,
    *         false - plansza z podanymi numerami nie jest możliwa do rozwiązania
    */
    bool checkSquarePuzzleIsSolvable(vector<int> numbersPuzzleForSquareBoard, int sizeSquareBoard);

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje klasa
    */
    void toString();
};

#endif // SQUAREBOARD_H
