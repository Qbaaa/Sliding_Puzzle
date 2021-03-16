#ifndef COMPUTERAI_H
#define COMPUTERAI_H

#include "Model/Player.h"
#include "Model/SquareBoard.h"

#include <map>

using namespace std;

/**
* Klasa ComputerAI jest przeznaczona do modelowania sztucznej inteligencji, która automatycznie będzie wybierała ruch
*/
class ComputerAI: public Player{

private:
    /**
    * Pole listMoveNumbers przechowuje listę przesunięć pól, jakie trzeba wykonać, aby ułożyć układankę przez wybrany algorytm
    */
    list<NumberPuzzle> listMoveNumbers;

    /**
    * Pole iteratorMoveNumber przechowuje iterator do pola z listy, którym sztuczna inteligencja ma się teraz ruszyć
    */
    list<NumberPuzzle>::iterator iteratorMoveNumber;

    /**
    * Pole goalBoard przechowuje numer pola oraz jego współrzędne, w których powinny znajdować się w końcowym stanie
    */
    map<int, Point<int>> goalBoard;

    /**
    * Pole nameAlgorithm przechowuje nazwę algorytmu, którym ma być rozwiązana układanka
    */
    string nameAlgorithm;

public:
    /**
    * Konstruktor argumentowy, który tworzy sztucznaą inteligencję. Ustawia atrybuty klasy podanymi wartościami
    *
    * @param _nameAlgorithm - nazwa algorytmu, którym ma być rozwiązana układanka
    * @param _board - obiekt kwadratowej planszy z ponumerowanymi polami, który ma być rozwiązany przez AI
    */
    ComputerAI(string _nameAlgorithm, SquareBoard _board );

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~ComputerAI();

    /**
    * Funkcja służy do wyszukania rozwiązania algorytmem A* dla podanej kwadratowej planszy
    *
    * @param _board - kwadratowa plansza z ponumerowanymi numerami
    */
    void algorithmAStar(SquareBoard *_board);

    /**
    * Funkcja służy do obliczenia, jakie ruchy można wykonać dla podanej kwadratowej planszy
    *
    * @param _board - kwadratowa plansza z ponumerowanymi numerami
    *
    * @return zwraca mape ruchów jakie można wykonć z podanej planszy w postaci nazwy ruchu (UP, DOWN, LEFT, RIGHT)
    *         oraz pola, którym będziemy się ruszać
    */
    map<string ,NumberPuzzle> possibleMove(SquareBoard *_board);

    /**
    * Funkcja służy do obliczenia odległości manhattan dla podanej kwadratowej planszy
    *
    * @param _gameSquareBoard - kwadratowa plansza z ponumerowanymi numerami
    *
    * @return liczba wieksza lub równa 0 - odległość manhattan dla podanej kwadratowej planszy
    */
    int manhattanDistance(vector<vector<NumberPuzzle>> _gameSquareBoard);

    /**
    * Funkcja służy do zmiany nazwy algorytmu, którym ma być rozwiązana układanka
    *
    * @param _nameAlgorithm - nowa nazwa algorytmu, którym ma być rozwiązana układanka
    *
    * @param _board - kwadratowa plansza z ponumerowanymi numerami, dla której ma byc rozwiązana układanka
    */
    void setNameAlgorithm(string _nameAlgorithm, SquareBoard _board);

    /**
    * Funkcja słuzy do wykonania automatycznego ruchu przez komputer
    *
    * @param _gameSquareBoard - kwadratowa plansza przechowywującą numery pól wraz z
    *                           współrzędnymi danych pól
    *
    * @return obiekt pola wybranego przez komputer, którym chce się poruszyć
    */
    NumberPuzzle* move(vector<vector<NumberPuzzle>> _gameSquareBoard);

    /**
    * Funkcja słuzy do wypisania wszystkich atrybutów jakie przechowuje klasa
    */
    void toString();
};

#endif // COMPUTERAI_H
