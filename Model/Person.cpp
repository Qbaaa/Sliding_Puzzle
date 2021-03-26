#define _CRT_SECURE_NO_WARNINGS
#include "Model/Person.h"

#include <iostream>

using namespace std;

Person::Person():Player(0) {}

Person::Person(int _moves): Player(_moves) {}

Person::~Person() {}

NumberPuzzle* Person::move(vector<vector<NumberPuzzle>> gameSquareBoard, int moveNumberPuzzle)
{
    int selectNumber = moveNumberPuzzle;
//    cout << "Ktory numer puzzla chcesz przesunac <1, " << (gameSquareBoard.size() * gameSquareBoard.size()) -1 << ">: ";
//    while (!(cin >> selectNumber) || selectNumber < 1 || selectNumber > ((int)gameSquareBoard.size() * (int)gameSquareBoard.size())-1 || getchar() != '\n')
//    {
//        cout << "BLAD! Podaj jeszcze raz: ";
//        while (getchar() != '\n');
//        cin.clear();
//        cin.sync();
//    }

    NumberPuzzle *returnNumberPuzzle = NULL;
    for(unsigned int i=0; i < gameSquareBoard.size(); i++)
    {
        for(unsigned int j=0; j < gameSquareBoard[i].size(); j++)
        {
            if(selectNumber == gameSquareBoard[i][j].getNumber())
                returnNumberPuzzle = &gameSquareBoard[i][j];
        }
    }

    return returnNumberPuzzle;
}

void Person::toString()
{
    cout << "MOVES: " << moves << endl;
}
