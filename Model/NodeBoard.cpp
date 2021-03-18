#include "Model/NodeBoard.h"
#include "Model/NumberPuzzle.h"

NodeBoard::NodeBoard(): visited(false), gScore(0), hScore(0), fScore(0)
{
    move = nullptr;
    nameMove = "START";
    board = nullptr;
    nextUP = nullptr;
    nextDOWN = nullptr;
    nextLEFT = nullptr;
    nextRIGHT = nullptr;
    prev = nullptr;
}

NodeBoard::NodeBoard(string _nameMove, NumberPuzzle *_moveNumber, SquareBoard *_board,  int _gScore, int _hScore, int _fScore):
    visited(false) ,gScore(_gScore), hScore(_hScore), fScore(_fScore)
{
    move = new NumberPuzzle(*_moveNumber);
    nameMove = _nameMove;
    board = new SquareBoard(*_board);
    nextUP = nullptr;
    nextDOWN = nullptr;
    nextLEFT = nullptr;
    nextRIGHT = nullptr;
    prev = nullptr;
}

NodeBoard::~NodeBoard()
{
    delete move;
    delete board;
    delete nextUP;
    delete nextDOWN;
    delete nextLEFT;
    delete nextRIGHT;
}

void NodeBoard::addNext(string _nameMove, NumberPuzzle *_moveNumber, SquareBoard *_board, int _gScore, int _hScore, int _fScore)
{
    if(_nameMove.compare("UP") == 0)
    {
        nextUP = new NodeBoard(_nameMove, _moveNumber, _board, _gScore, _hScore, _fScore);
        nextUP->prev = this;
    }
    else if(_nameMove.compare("DOWN") == 0)
    {
        nextDOWN = new NodeBoard(_nameMove, _moveNumber, _board, _gScore, _hScore, _fScore);
        nextDOWN->prev = this;
    }
    else if(_nameMove.compare("LEFT") == 0)
    {
        nextLEFT = new NodeBoard(_nameMove, _moveNumber, _board, _gScore, _hScore, _fScore);
        nextLEFT->prev = this;
    }
    else if(_nameMove.compare("RIGHT") == 0)
    {
        nextRIGHT = new NodeBoard(_nameMove, _moveNumber, _board, _gScore, _hScore, _fScore);
        nextRIGHT->prev = this;
    }
}

bool NodeBoard::getVisited() const
{
    return visited;
}

string NodeBoard::getNameMove() const
{
    return nameMove;
}

NumberPuzzle* NodeBoard::getMove() const
{
    return move;
}

SquareBoard* NodeBoard::getBoard() const
{
    return board;
}

int NodeBoard::getGScore() const
{
    return gScore;
}

int NodeBoard::getHScore() const
{
    return hScore;
}

int NodeBoard::getFScore() const
{
    return fScore;
}

NodeBoard* NodeBoard::getNext(string _move) const
{
    if(_move.compare("UP") == 0)
        return nextUP;
    else if(_move.compare("DOWN") == 0)
        return nextDOWN;
    else if(_move.compare("LEFT") == 0)
        return nextLEFT;
    else
        return nextRIGHT;
}

NodeBoard* NodeBoard::getPrev() const
{
    return prev;
}

void NodeBoard::setVisited(bool _visited)
{
    visited = _visited;
}

bool NodeBoard::operator ()( const NodeBoard* _node1, const NodeBoard* _node2 )
{
    return _node1->fScore > _node2->fScore;
}
