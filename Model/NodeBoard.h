#ifndef NODEBOARD_H
#define NODEBOARD_H

#include "Model/SquareBoard.h"

#include <string>

/**
* Klasa NodeBoard jest przeznaczona do modelowania węzłów, które posłużą do stworzenia drzewa grafowego
*/
class NodeBoard
{
private:

    /**
    * Pole visited służy do informowania, czy wierzchołek został już odwiedzony w drzewie czy nie
    */
    bool visited;

    /**
    * Pole nameMove przechowuje nazwę przesunięcia pola (UP, DOWN, LEFT, RIGHT)
    */
    string nameMove;

    /**
    * Pole move przechowuje obiekt pola, którym się przesuwamy
    */
    NumberPuzzle *move;

    /**
    * Pole board przechowuje obiekt planszy kwadratowej po wykonaniu ruchu obiektem move
    */
    SquareBoard *board;

    /**
    * Pole gScore przechowuje koszt (odległość) ścieżki od punktu początkowego do danego węzła
    */
    int gScore;

    /**
    * Pole hScore przechowuje szacunkowy koszt dla danego węzła do celu
    */
    int hScore;

    /**
    * Pole fScore przechowuje sumę kosztów z pola gScore i hScore
    */
    int fScore;

    /**
    * Pole nextUP przechowuje adres do następnego węzła, z którym ma być połoczony dany węzeł
    */
    NodeBoard *nextUP;

    /**
    * Pole nextDOWN przechowuje adres do następnego węzła, z którym ma być połoczony dany węzeł
    */
    NodeBoard *nextDOWN;

    /**
    * Pole nextLEFT przechowuje adres do następnego węzła, z którym ma być połoczony dany węzeł
    */
    NodeBoard *nextLEFT;

    /**
    * Pole nextRIGHT przechowuje adres do następnego węzła, z którym ma być połoczony dany węzeł
    */
    NodeBoard *nextRIGHT;

    /**
    * Pole prev przechowuje adres do poprzedniego węzła, z którym jest połączony dany węzeł
    */
    NodeBoard *prev;

public:
    /**
    * Konstruktor bezargumentowy, który tworzy węzeł. Ustawia atrybuty klasy domyślnimi wartościami
    */
    NodeBoard();

    /**
    * Konstruktor argumentowy, który tworzy węzeł. Ustawia atrybuty klasy podanymi wartościami
    *
    * @param _nameMove - nazwa przesunięcia pola (UP, DOWN, LEFT, RIGHT)
    *
    * @param _moveNumber - obiekt pola, którym się przesuwamy
    *
    * @param _board - obiekt kwadratowej planszy z ponumerowanymi polami, po wykonaniu ruchu
    *
    * @param _gScore - koszt (odległość) ścieżki od punktu początkowego do danego węzła
    *
    * @param _hScore - szacunkowy koszt dla danego węzła do celu
    *
    * @param _fScore - suma kosztów _gScore i _hScore
    */
    NodeBoard(string _nameMove, NumberPuzzle *_moveNumber, SquareBoard *_board,  int _gScore, int _hScore, int _fScore);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~NodeBoard();

    /**
    * Funkcja służy do stworzenia nowego węzła oraz połączenia go z poprzednim węzłem
    *
    * @param _nameMove - nazwa przesunięcia pola (UP, DOWN, LEFT, RIGHT)
    *
    * @param _moveNumber - obiekt pola, którym się przesuwamy
    *
    * @param _board - obiekt kwadratowej planszy z ponumerowanymi polami, po wykonaniu ruchu
    *
    * @param _gScore - koszt (odległość) ścieżki od punktu początkowego do nowego węzła
    *
    * @param _hScore - szacunkowy koszt dla nowego węzła do celu
    *
    * @param _fScore - suma kosztów _gScore i _hScore
    */
    void addNext(string _nameMove, NumberPuzzle *_moveNumber, SquareBoard *_board, int _gScore, int _hScore, int _fScore);

    /**
    * Funkcja udostępnia informacje czy wierzchołek został już odwiedzony w drzewie czy nie
    *
    * @return true - wierzcholek odwiedzony,
    *          false - wierzchołek nie odwiedzony
    */
    bool getVisited() const;

    /**
    * Funkcja udostępnia nazwę przesunięcia pola (UP, DOWN, LEFT, RIGHT)
    *
    * @return nazwa przesunięcia pola
    */
    string getNameMove() const;

    /**
    * Funkcja udostępnia obiekt pola, którym się przesuwamy w danym węźle
    *
    * @return obiekt pola, którym się przesuwamy w danym węźle
    */
    NumberPuzzle* getMove() const;

    /**
    * Funkcja udostępnia obiekt planszy kwadratowej po wykonaniu ruchu
    *
    * @return obiekt planszy kwadratowej
    */
    SquareBoard* getBoard() const;

    /**
    * Funkcja udostępnia koszt (odległość) ścieżki od punktu początkowego dla danego węzła
    *
    * @return koszt (odległość) ścieżki
    */
    int getGScore() const;

    /**
    * Funkcja udostępnia szacunkowy koszt dla danego węzła do celu
    *
    * @return koszt do celowego węzła z danego węzła
    */
    int getHScore() const;

    /**
    * Funkcja udostępnia sumę kosztów z _gScore i _hScore
    *
    * @return suma kosztów z _gScore i _hScore
    */
    int getFScore() const;

    /**
    * Funkcja udostępnia adres do następnego węzła, z którym jest połączony dany węzeł
    *
    * @param _move - nazwa przesunięcia pola (UP, DOWN, LEFT, RIGHT), z którego wchodzi dany węzeł
    *
    * @return adres do następnego węzła
    */
    NodeBoard* getNext(string _move) const;

    /**
    * Funkcja udostępnia adres do poprzedniego węzła, z którym jest połączony dany węzeł
    *
    * @return adres do poprzedniego węzła
    */
    NodeBoard* getPrev() const;

    /**
    * Funkcja słuzy do zmiany stanu odwiedzenia wierzchołak
    *
    * @param true - wierzcholek odwiedzony,
    *        false - wierzchołek nie odwiedzony
    */
    void setVisited(bool _visited);

    /**
    * Funkcja słuzy do przeciążenia operatora '()' dla danej klasy
    *
    * Funkcja służy do porównania, które pole fScore z klas jest większe
    *
    * @param _node1 - obiekt pierwszego węzła do porównania
    *
    * @param _node2 - obiekt drugiego węzła do porównania
    *
    * @return  true - obiekt pierwszego węzła jest większy od węzła drugiego,
    *          false - obiekt pierwszego węzła NIE jest większy od węzła drugiego
    */
    bool operator ()( const NodeBoard* _node1, const NodeBoard* _node2 );
};

#endif // NODEBOARD_H
