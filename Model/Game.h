#ifndef GAME_H
#define GAME_H

#include "Model/SquareBoard.h"
#include "Model/Player.h"

#include <string>

using namespace std;

/**
* Klasa Game jest przeznaczona do modelowania rozgrywki gry w Puzzle
*
* Zadaniem klasy jest przechowywanie obiektu kwadratowej planszy oraz
* obiektu gracza, który bedzie grał
*/
class Game{

private:
    /**
    * Pole squareBoard przechowuje obiekt kwadratowej planszy przechowywującej pola ponumerowane(klasy NumberPuzzle)
    */
    SquareBoard *squareBoard;

    /**
    * Pole player przechowuje obiekt gracza, który obecnie gra (osoba czy komputer)
    */
    Player *player;

public:
    /**
    * Konstruktor argumentowy, który tworzy rozgrywkę gry . Ustawia atrybuty klasy podanymi wartościami
    *
    * @param sizeSquareBoard - rozmiar kwadratowej planszy
    * @param playerType - gracz, który ma grać w daną gre
    *                  ("person"    - osoba, która będzie wykonywać ręczne ruchu,
    *                   "computerAI - sztuczna inteligencja, która będzie wykonywać auqtomatyczne ruchu)
    */
    Game(int sizeSquareBoard, string playerType);

    /**
    * Konstruktor argumentowy, który tworzy rozgrywkę gry . Ustawia atrybuty klasy podanymi wartościami
    *
    * @param _squareBoard - obiek planszy kwadratowej
    * @param _playerType -  gracz, który ma grać w daną gre
    *                      ("person"    - osoba, która będzie wykonywać ręczne ruchu,
    *                       "computerAI - sztuczna inteligencja, która będzie wykonywać auqtomatyczne ruchu)
    * @param _moves - ilośc punktów posiadanych przez gracza
    */
    Game(SquareBoard _squareBoard, string _playerType, int _moves);

    /**
    * Konstruktor kopiujący, który służy do stworzenia nowej gry poprzez skopiowanie atrybutów od innego obiektu gry
    *
    * @param game - wartość innej rozgrywki gry, który ma zostać skopiowany
    */
    Game(const Game& game);

    /**
    * Destruktor służy do zwolnienia pamięci danego obiektu
    */
    ~Game();

    /**
     * Funkcja udostępnia obiekt kwadratowej planszy przechowywującej pola ponumerowane(klasy NumberPuzzle)
    *
    * @return obiekt kwadratowej planszy przechowywującej pola ponumerowane
    */
    SquareBoard* getSquareBoard() const;

    /**
     * Funkcja udostępnia obiekt gracza, który obecnie gra
    *
    * @return obiekt gracza, który obecnie gra (osoba lub komputer)
    */
    Player* getPlayer() const;

    /**
    * Funkcja słuzy do zmiany obiektu dla kwadratowej planszy przechowywującej pola ponumerowane
    *
    * @param _squareBoard - nowy obiekt kwadratowej planszy przechowywującej pola ponumerowane
    */
    void setSquareBoard(SquareBoard* _squareBoard);

    /**
    * Funkcja słuzy do zmiany obiektu dla gracza, który obecnie gra
    *
    * @param _player - nowy obiekt gracza, który obecnie gra (osoba lub komputer)
    */
    void setPlayer(Player* _player);

    /**
    * Funkcja służy do uruchomienia gry w puzzle
    */
    void playGame();

    /**
    * Funkcja służy do sprawdzenia czy podany ruch przez użytkownika z wybranym polem jest możliwy do wykonania
    *
    * @param numberPuzzleMove - obiekt pola, którym użytkownik chce się poruszyć
    *
    * @return true - dany ruch użytkownika z wybranym polem jest możliwy do wykonania
    *        false - dany ruch użytkownika z wybranym polem NIE jest możliwy do wykonania
    */
    bool checkCorrectMove(NumberPuzzle numberPuzzleMove);

    /**
    * Funkcja służy do sprawdzenia czy dany obiekt kwadratowej planszy z numerami pól jest ułożony końcowym stanie
    *
    * @return true - kwadratowa plansza z numerami pól jest ułożona w końcowym stanie,
    *        false - kwadratowa plansza z numerami pól NIE jest ułożona w końcowym stanie
    */
    bool checkIsGameEnd();
};

#endif // GAME_H
