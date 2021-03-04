#include "Model/SquareBoard.h"
#include "Model/NumberPuzzle.h"
#include "Model/Point.h"

#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>

SquareBoard::SquareBoard():size(2)
{
    initSquareBoard(2);
}

SquareBoard::SquareBoard(int _size):size(_size)
{
    initSquareBoard(_size);
}

SquareBoard::~SquareBoard() {}

void SquareBoard::initSquareBoard(int _size)
{
    startNumbersPuzzle.clear();
    gameNumbersPuzzle.clear();

    for(int i=0; i < _size; i++)
        gameNumbersPuzzle.push_back(vector<NumberPuzzle>());

    startNumbersPuzzle = vector<int>(randomNumbersPuzzle(_size));
    vector<int>::iterator startNumbersPuzzleIterator = startNumbersPuzzle.begin();

    for(int i=0; i < _size; i++)
    {
        for(int j=0; j < _size; j++)
        {
            gameNumbersPuzzle[i].push_back(NumberPuzzle(*startNumbersPuzzleIterator, new Point<int>(j + 1, _size - i)));
            startNumbersPuzzleIterator++;
        }
    }
}

int SquareBoard::getSize() const
{
    return size;
}

vector<vector<NumberPuzzle>> SquareBoard::getGameNumberPuzzle() const
{
    return gameNumbersPuzzle;
}

vector<int> SquareBoard::getStartNumberPuzzle() const
{
    return startNumbersPuzzle;
}

void SquareBoard::setSizeAndStartAndGameNumberPuzzle(int _size)
{
    size = _size;
    initSquareBoard(_size);
}

vector<int> SquareBoard::randomNumbersPuzzle(int sizeSquareBoard)
{
    list<int> listNumbersPuzzle;
    vector<int> randomNumbersPuzzleForSquareBoard;
    int amountNumbersPuzzle = sizeSquareBoard * sizeSquareBoard;
    srand(time(NULL));

    do
    {
        listNumbersPuzzle.clear();
        randomNumbersPuzzleForSquareBoard.clear();

        for(int i=0; i < amountNumbersPuzzle; i++)
            listNumbersPuzzle.push_back(i);

        int randomNumberIndex;
        list<int>::iterator randomNumberIterator;

        for(int i=0; i < amountNumbersPuzzle; i++)
        {
            randomNumberIndex = rand() % listNumbersPuzzle.size();
            randomNumberIterator = listNumbersPuzzle.begin();

            for(int i = 0; i < randomNumberIndex; i++)
                randomNumberIterator++;

            randomNumbersPuzzleForSquareBoard.push_back(*randomNumberIterator);
            listNumbersPuzzle.remove(*randomNumberIterator);
        }

    }while(!checkSquarePuzzleIsSolvable(randomNumbersPuzzleForSquareBoard, sizeSquareBoard));

    return randomNumbersPuzzleForSquareBoard;
}

bool SquareBoard::checkSquarePuzzleIsSolvable(vector<int> numbersPuzzleForSquareBoard, int sizeSquareBoard)
{
    int inversionCount = 0;
    int x = 1;
    int y = sizeSquareBoard;
    int zeroY = 1;

    for(unsigned int i=0; i < numbersPuzzleForSquareBoard.size()-1; i++)
    {
        if(numbersPuzzleForSquareBoard[i] != 0)
        {
            if(x == sizeSquareBoard)
            {
                y--;
                x = 0;
            }

            for(unsigned int j=i+1; j < numbersPuzzleForSquareBoard.size(); j++)
            {
                if(numbersPuzzleForSquareBoard[j] != 0)
                {
                    if(numbersPuzzleForSquareBoard[i] > numbersPuzzleForSquareBoard[j])
                        inversionCount++;
                }
            }
            x++;
        }
        else
        {
            zeroY = y;
        }
    }

    bool returnValue = false;
    if(sizeSquareBoard % 2 == 0)
    {
        if(zeroY % 2 == 0)
        {
            if(inversionCount % 2 != 0)
                returnValue = true;
        }
        else
        {
            if(inversionCount % 2 == 0)
                returnValue = true;
        }
    }
    else
    {
        if(inversionCount % 2 == 0)
            returnValue = true;
    }

    return returnValue;
}

void SquareBoard::toString()
{
    cout << "SquareBoard { " << endl;
    cout << "size: " << size << endl;
    cout << "startNumbersPuzzle: [ " << endl;
    for(int elem : startNumbersPuzzle)
        cout << elem << " ";
    cout << endl;
    cout << "]," << endl;
    cout << "gameNumbersPuzzle: [ " << endl;
    for(unsigned int i=0; i < gameNumbersPuzzle.size(); i++)
    {
        cout << "[" << endl;
        for(unsigned int j=0; j < gameNumbersPuzzle[i].size(); j++)
        {
            gameNumbersPuzzle[i][j].toString();
            cout << endl;
        }
        cout << "]" << endl;
    }
    cout << "] ";
    cout << "} ";
}
