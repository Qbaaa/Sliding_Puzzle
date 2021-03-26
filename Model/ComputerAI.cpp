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
    else if( _nameAlgorithm.compare("IDA*") == 0 )
    {
        nameAlgorithm = _nameAlgorithm;
        algorithmIDAStar(&_board);
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

//        cout << "Start Board" << endl;
//        cout << "fScore = gScore + hScore -> " << current->getFScore() << " = " << current->getGScore() << " + " << current->getHScore() << endl;
//        current->getBoard()->printGameSquareBoard();
//        cout << "-------------------POSSIBLE MOVE--------------------"<<endl;

        for( map<string, NumberPuzzle>::iterator it = possibleNextNumberMove.begin(); it != possibleNextNumberMove.end(); it++ )
        {
             SquareBoard boardNextPossibleMove(*current->getBoard());
             boardNextPossibleMove.swapNumberPuzzleWithEmptyPuzzle(&it->second);

             if( find(closeList.begin(), closeList.end(), boardNextPossibleMove) == end(closeList) )
             {
                 hScore = manhattanDistance(boardNextPossibleMove.getGameNumberPuzzle());
//                 cout << "Move: " << it->first << " Number: " << it->second.getNumber() << endl;
//                 cout << "fScore = gScore + hScore -> " << current->getGScore() + hScore + 1 << " = " << current->getGScore() + 1 << " + " << hScore << endl;
//                 boardNextPossibleMove.printGameSquareBoard();
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
//        cout << "---------------------END POSSIBLE MOVE--------------"<<endl;
    }
//    cout << "END Board" << endl;
//    cout << "Move: " << current->getNameMove() <<  "Number: " << current->getMove()->getNumber() << endl;
//    current->getBoard()->printGameSquareBoard();

    while(current->getMove()->getNumber() != -1)
    {
        listMoveNumbers.push_front(*current->getMove());
        current = current->getPrev();
    }

    iteratorMoveNumber = listMoveNumbers.begin();
    delete root;
}

void ComputerAI::algorithmIDAStar(SquareBoard *board)
{
    int currentFScore = 0;
    int nextFScore;
    int gScore = 0;
    int hScore = manhattanDistance(board->getGameNumberPuzzle());
    nextFScore = gScore + hScore;
    NodeBoard *root = new NodeBoard("START", new NumberPuzzle(-1, new Point<int>(-1, -1)), board, gScore, hScore, nextFScore);
    NodeBoard *gameEnd = nullptr;
    list< SquareBoard > closeList;
    closeList.push_back(*root->getBoard());
    currentFScore = nextFScore;
    nextFScore = -1;

//    cout << "START: " << endl;
//    cout << "fScore = gScore + hScore -> " << root->getFScore()<< " = " << root->getGScore() << " + " << hScore << endl;
//    board->printGameSquareBoard();

    while(gameEnd == nullptr )
    {
        gameEnd = iterativeDeepedingAStar(&currentFScore, &nextFScore, root, &closeList);
        currentFScore = nextFScore;
        nextFScore = -1;
    }
//    cout << "END: " << endl;
//    cout << "fScore = gScore + hScore -> " << gameEnd->getFScore()<< " = " << gameEnd->getGScore() << " + " << gameEnd->getHScore() << endl;
//    gameEnd->getBoard()->printGameSquareBoard();
    while(gameEnd->getMove()->getNumber() != -1)
    {
        listMoveNumbers.push_front(*gameEnd->getMove());
        gameEnd = gameEnd->getPrev();
    }

    iteratorMoveNumber = listMoveNumbers.begin();
    delete root;
}

NodeBoard* ComputerAI::iterativeDeepedingAStar(int *_currentFScore, int *_nextFScore, NodeBoard *node, list< SquareBoard > *_closeList)
{
    if(node->getVisited() == false)
    {
//        cout<<"----------------------" <<endl;
        map<string, NumberPuzzle> possibleNextNumberMove = map<string, NumberPuzzle>(possibleMove(node->getBoard()));

        for( map<string, NumberPuzzle>::iterator it = possibleNextNumberMove.begin(); it != possibleNextNumberMove.end(); it++ )
        {
             SquareBoard boardNextPossibleMove(*node->getBoard());
             boardNextPossibleMove.swapNumberPuzzleWithEmptyPuzzle(&it->second);

             if( find(_closeList->begin(), _closeList->end(), boardNextPossibleMove) == end(*_closeList) )
             {
                 int hScore = manhattanDistance(boardNextPossibleMove.getGameNumberPuzzle());
//                 cout << "Move: " << it->first << " Number: " << it->second.getNumber() << endl;
//                 cout << "fScore = gScore + hScore -> " << node->getGScore() + hScore + 1 << " = " << node->getGScore() + 1 << " + " << hScore << endl;
//                 boardNextPossibleMove.printGameSquareBoard();

                 node->addNext(it->first, &it->second, &boardNextPossibleMove, node->getGScore() + 1, hScore, node->getGScore() + hScore + 1);
                 _closeList->push_back(boardNextPossibleMove);
                 if(hScore == 0)
                 {
                    return node->getNext(it->first);
                 }
             }
         }
//        cout<<"-----------END---------" <<endl;
        node->setVisited(true);
    }

    NodeBoard *returnValue = nullptr;

        if(node->getNext("UP") != nullptr)
        {
            if(*_currentFScore >= node->getNext("UP")->getFScore())
            {
                returnValue = iterativeDeepedingAStar(_currentFScore, _nextFScore, node->getNext("UP"), _closeList );
                if( returnValue != nullptr )
                    return returnValue;
            }
            else
            {
                if(*_nextFScore == -1 || *_nextFScore > node->getNext("UP")->getFScore())
                    *_nextFScore = node->getNext("UP")->getFScore();
            }
        }

        if(node->getNext("DOWN") != nullptr)
        {
            if(*_currentFScore >= node->getNext("DOWN")->getFScore())
            {
                returnValue = iterativeDeepedingAStar(_currentFScore, _nextFScore, node->getNext("DOWN"), _closeList );
                if( returnValue != nullptr )
                    return returnValue;
            }
            else
            {
                if(*_nextFScore == -1 || *_nextFScore > node->getNext("DOWN")->getFScore())
                    *_nextFScore = node->getNext("DOWN")->getFScore();
            }
        }

        if(node->getNext("LEFT") != nullptr)
        {
            if(*_currentFScore >= node->getNext("LEFT")->getFScore())
            {
                returnValue =  iterativeDeepedingAStar(_currentFScore, _nextFScore, node->getNext("LEFT"), _closeList );
                if( returnValue != nullptr )
                    return returnValue;
            }
            else
            {
                if(*_nextFScore == -1 || *_nextFScore > node->getNext("LEFT")->getFScore())
                    *_nextFScore = node->getNext("LEFT")->getFScore();
            }
        }

        if(node->getNext("RIGHT") != nullptr)
        {
            if(*_currentFScore >= node->getNext("RIGHT")->getFScore())
            {
                returnValue = iterativeDeepedingAStar(_currentFScore, _nextFScore, node->getNext("RIGHT"), _closeList );
                if( returnValue != nullptr )
                    return returnValue;
            }
            else
            {
                if(*_nextFScore == -1 || *_nextFScore > node->getNext("RIGHT")->getFScore())
                    *_nextFScore = node->getNext("RIGHT")->getFScore();
            }
        }
        return nullptr;
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
    else if( _nameAlgorithm.compare("IDA*") == 0 )
    {
        nameAlgorithm = _nameAlgorithm;
        algorithmIDAStar(&_board);
    }
}

NumberPuzzle* ComputerAI::move(vector<vector<NumberPuzzle>> _gameSquareBoard, int _moveNumberPuzzle)
{
    list<NumberPuzzle>::iterator prevIterator = iteratorMoveNumber;
//    cout << "Move number: " << prevIterator->getNumber() << endl;
    iteratorMoveNumber++;

    return &*prevIterator;
}

NumberPuzzle* ComputerAI::movePrevious()
{
    iteratorMoveNumber--;
    moves--;
    return &*iteratorMoveNumber;
}

void ComputerAI::toString()
{
    cout << "MOVES: " << moves << endl;
    cout << "Name Algorithm: " << nameAlgorithm << endl;
}
