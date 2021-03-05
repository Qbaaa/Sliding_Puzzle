#ifndef COMPUTERAI_H
#define COMPUTERAI_H

#include "Model/Player.h"

#include <list>

using namespace std;

class ComputerAI: public Player{

private:
    list<int> listMoveNumbers;
    list<int>::iterator iteratorMoveNumber;

public:
    ComputerAI();
    ~ComputerAI();

    NumberPuzzle* move(vector<vector<NumberPuzzle>> gameSquareBoard);
    void toString();
};

#endif // COMPUTERAI_H
