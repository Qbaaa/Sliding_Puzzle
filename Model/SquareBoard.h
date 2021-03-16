#ifndef SQUAREBOARD_H
#define SQUAREBOARD_H

#include <list>
#include <vector>
class NumberPuzzle;

using namespace std;

/**
* Klasa SquareBoard jest przeznaczona do modelowania kwadratowej planszy przechowywującej klasy NumberPuzzle
*
* Zadaniem klasy jest przechowywanie rozmiaru kwadratowej planszy, adresu numeru pola przechowującego numer 0(puste pole)
* tablicy numerów dla planszy(początkowy stan rozmieszczenia numerów) oraz dwuwymiarowej tablicy, która przedstawia kwadratową planszę
*/
class SquareBoard{

private:
    /**
    * Pole size przechowuje liczbę, która określa rozmiar kwadratowej planszy w grze
    */
    int size;

    /**
    * Pole zeroNumberPuzzle przechowuje adres do numeru pola, które przechowuje numer 0(puste pole)
    */
    NumberPuzzle *zeroNumberPuzzle;

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
    * Konstruktor argumentowy, który tworzy kwadratową plansze. Ustawia atrybuty klasy podaną wartością
    *
    * Konstruktor tworzy kwadratową planszę z podanymi polami pól
    *
    * @param _startBoard - tablica pól dla początkowego stanu gry
    * @param _gameBoard - tablica pól dla planszy, dla której jest rozgrywana rozgrywka
    */
    SquareBoard(vector<int> _startBoard, vector<int> _gameBoard);

    /**
    * Konstruktor kopiujący, który służy do stworzenia nowej planszy poprzez skopiowanie atrybutów od innego obiektu planszy
    *
    * @param copySquareBoard - wartość innej planszy, który ma zostać skopiowany
    */
    SquareBoard(const SquareBoard& copySquareBoard);

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
     * Funkcja udostępnia adres do numeru pola, które przechowuje numer 0(puste pole)
    *
    * @return adres pola, które przechowuje numer 0(puste pole)
    */
    NumberPuzzle* getZeroNumberPuzzle() const;

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
    * Funkcja służy do zamiany miejscami dwóch pól numerów dla planszy kwadratowej
    *
    * @param numberPuzzle - adres pola, które ma byż zamienione z pustym polem
    */
    void swapNumberPuzzleWithEmptyPuzzle(NumberPuzzle *numberPuzzle);

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje klasa
    */
    void toString();

    /**
    * Funkcja słuzy do wypisania kwadratowej planszy wraz z rozmieszczonymi polami numerów
    */
    void printGameSquareBoard();

    /**
    * Funkcja słuzy do przeciążenia operatora '==' dla danej klasy
    *
    * Funkcja porównuje pola gameNumbersPuzzle z klas
    *
    * @param ele - adres obiektu, który ma być porównywany
    *
    * @return  true - dane pola obiektu danej klasy z podaym adresem obiektu jest równy sobie,
    *          false - dane pola obiektu danej klasy z podaym adresem obiektu NIE jest równy sobie
    */
    bool operator==(const SquareBoard& ele);
};

#endif // SQUAREBOARD_H
