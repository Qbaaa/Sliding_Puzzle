#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H

#include <Model/Game.h>

/**
* Klasa ControllerGame jest przeznaczona do przyjmowania danych od użytkwonika i reagowanie na poczynania jego,
* zarządzając aktualizacje modelu oraz odświeżenie widoków
*/
class ControllerGame
{
private:
    Game *game;

public:
    ControllerGame();
    ~ControllerGame();

    Game* getGame() const;

    /**
    * Funkcja służy do wczytania stanu zapisanej gry przez użytkownika
    *
    * @param fileName - tablica znaków, która przechowuje nazwę pliku, w którym znajduje się
    *                   zapisany stan gry
    *
    * @return true - wczytanie stanu gry powiodło się,
    *        false - wczytanie stanu gry NIE powiodło się
    */
    bool handleLoad(string fileName);

    /**
    * Funkcja służy do stworzenia modelu rozgrywki gry w Puzzle (planszy kwadratowej oraz użytkownika) i widoku
    *
    * @param _size - rozmiar planszy, wybrany przez użtkownika
    *
    * @param _typePalyer - typ użytkownika, wybrany przez użtkownika
    *
    * @param _typeAlgorithm - typ algorytmu, którym ma być rozwiązana układanka, wybrany przez użtkownika
    */
    void handleStart(int _size, string _typePalyer, string _typeAlgorithm);

    /**
    * Funkcja służy do zapisania stanu gry prowadzonej przez użytkownika
    *
    * @return true - zapisanie stanu gry powiodło się,
    *        false - zapisanie stanu gry NIE powiodło się
    */
    bool handleSave();

    /**
    * Funkcja służy do obsługi ruchu wykonanego przez osobę
    *
    * @param movePuzzle - numer pola, który wybrała osoba
    *
    * @return liczba dodatnia - numer pola, którym ma się poruszyć w interfejsie graficznym
    *         -1 - wybrany numer pola jest błędny
    */
    int handleMovePuzzle(int movePuzzle);

    /**
    * Funkcja służy do wrócenia do początkowego stanu gry
    */
    void handleReset();

    /**
    * Funkcja służy do wykonania ruch do przodu przez sztuczną inteligencję
    *
    * @return liczba dodatnia - numer pola, który ma się poruszyć w interfejsie graficznym
    *         -1 - wybrany numer pola jest błędny
    */
    int handleNextComputer();

    /**
    * Funkcja służy do wykonania ruch wstecz przez sztuczną inteligencję
    *
    * @return liczba dodatnia - numer pola, który ma się poruszyć w interfejsie graficznym
    *         -1 - wybrany numer pola jest błędny
    */
    int handlePreviousComputer();
};

#endif // CONTROLLERGAME_H
