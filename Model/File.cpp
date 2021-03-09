#include "Model/File.h"
#include "Model/Game.h"

#include <time.h>
#include <string.h>
#include <fstream>
#include <iostream>

bool File::save(Game game)
{
    string fileName;
    char dateTime[30];
    bool returnCorrectFile = false;
    time_t timeN;
    struct tm *timeInfo;

    fileName.append("Puzzle");
    fileName.append(to_string(game.getSquareBoard()->getSize() * game.getSquareBoard()->getSize()));
    time(&timeN);
    timeInfo = localtime(&timeN);
    strftime(dateTime, sizeof(dateTime), "_%d_%m_%Y_%H%M%S.dat", timeInfo);
    fileName.append(dateTime);
    cout <<fileName<<endl;
    ofstream file;
    file.open(fileName, ios::out|ios::trunc);

    if (!file.good())
    {
        cout << "BLAD: problem z plikiem." << endl;
    }
    else
    {
        file << "P " << game.getSquareBoard()->getSize() << " " << game.getSquareBoard()->getSize() * game.getSquareBoard()->getSize() <<endl;
        file << "u " << game.getPlayer()->getMoves() << endl;

        for(int i=0; i < game.getSquareBoard()->getSize() * game.getSquareBoard()->getSize(); i++)
            file << game.getSquareBoard()->getStartNumberPuzzle()[i] << " ";
        file << endl;

        for(int i=0; i < game.getSquareBoard()->getSize(); i++)
            for(int j=0; j < game.getSquareBoard()->getSize(); j++)
                   file << game.getSquareBoard()->getGameNumberPuzzle()[i][j].getNumber() << " ";
        file << endl;
        returnCorrectFile = true;
    }

    file.close();
    return returnCorrectFile;
}

list<Game> File::load(string fileName)
{
    char checkFileChar;
    int sizeBoard;
    int sizeNumbers;
    char typePlayerChar;
    int moves;
    vector<int> startGamePuzzle;
    vector<int> gamePuzzle;
    list<Game> returnList = list<Game>();
    int ele;

    ifstream file;
    file.open(fileName);

    if (!file.good())
    {
        cout << "BLAD: problem z plikiem." << endl;
        return returnList;
    }
    else
    {
        file >> checkFileChar;

        if(checkFileChar != 'P')
            return returnList;

        file >> sizeBoard;
        file >> sizeNumbers;
        file >> typePlayerChar;
        if(typePlayerChar != 'u')
            return returnList;
        file >> moves;

        for(int i=0; i < sizeNumbers; i++)
        {
            file >> ele;
            startGamePuzzle.push_back(ele);
        }

        for(int i=0; i < sizeNumbers; i++)
        {
            file >> ele;
            gamePuzzle.push_back(ele);
        }
    }

    file.close();
    returnList.push_back(Game(SquareBoard(startGamePuzzle, gamePuzzle), "person", moves));
    return returnList;
}
