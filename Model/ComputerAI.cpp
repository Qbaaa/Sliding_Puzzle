#include "Model/ComputerAI.h"
#include "Model/Point.h"
#include "Model/NodeBoard.h"
#include <queue>
#include <algorithm>

ComputerAI::ComputerAI(string _nameAlgorithm, SquareBoard _board )
{
    int number = 1;
    for(int i=0; i < _board.getSize(); i++)
    {
        for(int j=0; j < _board.getSize(); j++)
        {
            if(number != _board.getSize() * _board.getSize())
                goalBoard.insert(pair<int, Point<int>>(number, Point<int>(j + 1, _board.getSize() - i)) );
            else
                goalBoard.insert(pair<int, Point<int>>(0, Point<int>(j + 1, _board.getSize() - i)) );
            number++;
        }
    }

    if( _nameAlgorithm.compare("A*") == 0 )
    {
        nameAlgorithm = _nameAlgorithm;
        algorithmAStar(&_board);
    }
}

ComputerAI::~ComputerAI() {}

void ComputerAI::algorithmAStar(SquareBoard *board)
{
    int gScore = 0;
    int hScore = manhattanDistance(board->getGameNumberPuzzle());
    int fScore = gScore + hScore;
    bool checkLoop = true;
    NodeBoard *current = nullptr;
    NodeBoard *root = new NodeBoard("START", new NumberPuzzle(-1, new Point<int>(-1, -1)), board, gScore, hScore, fScore);
    priority_queue < NodeBoard*, vector < NodeBoard* >, NodeBoard > openList;
    list< SquareBoard > closeList;
    openList.push(root);

    while(checkLoop)
    {
        current = openList.top();
        openList.pop();
        closeList.push_back(*current->getBoard());

        map<string, NumberPuzzle> possibleNextNumberMove = map<string, NumberPuzzle>(possibleMove(current->getBoard()));

        cout << "Start Board" << endl;
        cout << "fScore = gScore + hScore -> " << current->getFScore() << " = " << current->getGScore() << " + " << current->getHScore() << endl;
        current->getBoard()->printGameSquareBoard();
        cout << "-------------------POSSIBLE MOVE--------------------"<<endl;

        for( map<string, NumberPuzzle>::iterator it = possibleNextNumberMove.begin(); it != possibleNextNumberMove.end(); it++ )
        {
             SquareBoard boardNextPossibleMove(*current->getBoard());
             boardNextPossibleMove.swapNumberPuzzleWithEmptyPuzzle(&it->second);

             if( find(closeList.begin(), closeList.end(), boardNextPossibleMove) == end(closeList) )
             {
                 hScore = manhattanDistance(boardNextPossibleMove.getGameNumberPuzzle());
                 cout << "Move: " << it->first << " Number: " << it->second.getNumber() << endl;
                 cout << "fScore = gScore + hScore -> " << current->getGScore() + hScore + 1 << " = " << current->getGScore() + 1 << " + " << hScore << endl;
                 boardNextPossibleMove.printGameSquareBoard();
                 current->addNext(it->first, &it->second, &boardNextPossibleMove, current->getGScore() + 1, hScore, current->getGScore() + hScore + 1);

                 openList.push(current->getNext(it->first));
                 if( current->getNext(it->first)->getHScore() == 0)
                 {
                    checkLoop = false;
                    current = current->getNext(it->first);
                    break;
                 }
             }
         }
        cout << "---------------------END POSSIBLE MOVE--------------"<<endl;
    }
    cout << "END Board" << endl;
    cout << "Move: " << current->getNameMove() <<  "Number: " << current->getMove()->getNumber() << endl;
    current->getBoard()->printGameSquareBoard();
    delete root;
}

map<string, NumberPuzzle> ComputerAI::possibleMove(SquareBoard *board)
{
    map<string, NumberPuzzle> possibleMove;

    if( board->getZeroNumberPuzzle()->getPoint()->getY() - 1 >= 1 )
        possibleMove.insert(pair<string, NumberPuzzle>("UP", board->getGameNumberPuzzle()
                                                       [board->getSize() - (board->getZeroNumberPuzzle()->getPoint()->getY() - 1)]
                                                       [board->getZeroNumberPuzzle()->getPoint()->getX() - 1]) );

    if( board->getZeroNumberPuzzle()->getPoint()->getY() + 1 <= board->getSize() )
        possibleMove.insert(pair<string, NumberPuzzle>("DOWN", board->getGameNumberPuzzle()
                                                        [board->getSize() - (board->getZeroNumberPuzzle()->getPoint()->getY() + 1)]
                                                        [board->getZeroNumberPuzzle()->getPoint()->getX() - 1]) );

    if( board->getZeroNumberPuzzle()->getPoint()->getX() + 1 <= board->getSize() )
        possibleMove.insert(pair<string, NumberPuzzle>("LEFT", board->getGameNumberPuzzle()
                                                       [board->getSize() - (board->getZeroNumberPuzzle()->getPoint()->getY())]
                                                       [board->getZeroNumberPuzzle()->getPoint()->getX()]) );

    if( board->getZeroNumberPuzzle()->getPoint()->getX() - 1 >= 1 )
        possibleMove.insert(pair<string, NumberPuzzle>("RIGHT", board->getGameNumberPuzzle()
                                                       [board->getSize() - (board->getZeroNumberPuzzle()->getPoint()->getY())]
                                                       [board->getZeroNumberPuzzle()->getPoint()->getX() - 2]) );

    return possibleMove;
}

int ComputerAI::manhattanDistance(vector<vector<NumberPuzzle>> gameSquareBoard)
{
    int sumManhattan = 0;
    int eleManhattan = 0;

    for(unsigned int i=0; i < gameSquareBoard.size(); i++)
    {
        for(unsigned int j=0; j < gameSquareBoard.size(); j++)
        {
            if( gameSquareBoard[i][j].getNumber() != 0 )
            {
                eleManhattan = abs( gameSquareBoard[i][j].getPoint()->getX() - goalBoard.find(gameSquareBoard[i][j].getNumber())->second.getX() ) +
                        abs( gameSquareBoard[i][j].getPoint()->getY() - goalBoard.find(gameSquareBoard[i][j].getNumber())->second.getY() );
                sumManhattan = sumManhattan + eleManhattan;
            }
        }
    }
    return sumManhattan;
}

void ComputerAI::setNameAlgorithm(string _nameAlgorithm, SquareBoard _board)
{
    if( _nameAlgorithm.compare("A*") == 0 )
    {
        nameAlgorithm = _nameAlgorithm;
        algorithmAStar(&_board);
    }
}

NumberPuzzle* ComputerAI::move(vector<vector<NumberPuzzle>> gameSquareBoard)
{}

void ComputerAI::toString()
{}
