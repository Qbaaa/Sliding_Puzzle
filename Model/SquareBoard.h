#ifndef SQUAREBOARD_H
#define SQUAREBOARD_H

#include <vector>
class NumberPuzzle;

using namespace std;

class SquareBoard{

private:
    vector<vector<NumberPuzzle>> numbersPuzzle;

public:
    SquareBoard();
    ~SquareBoard();

};

#endif // SQUAREBOARD_H
