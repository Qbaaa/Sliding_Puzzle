#ifndef FILE_H
#define FILE_H

#include "Model/Game.h"

/**
* Klasa File jest przeznaczona do modelowania obsługi plików
*
* Zadaniem klasy jest zapisanie stanu gry lub wczytanie stanu gry z wybranego pliku
*/
class File{

public:
    /**
    * Funkcja służy do zapisania stanu gry przez użytkownika
    *
    * @return true - zapysanie stanu gry powiodło się,
    *        false - zapisanie stanu gry NIE powiodło się
    */
    bool save(Game *game);

    /**
    * Funkcja służy do wczytania stanu zapisanej gry przez użytkownika
    *
    * @param fileName - tablica znaków, która przechowuje nazwę pliku, w którym znajduje się
    *                   zapisany stan gry
    *
    * @return lista z jednym elementem obiektu - wczytanie zapisanej gry powiodło się,
    *         pusta lista - wczytanie zapisanej gry NIE powiodło się
    */
    list<Game> load(string fileName);
};

#endif // FILE_H
