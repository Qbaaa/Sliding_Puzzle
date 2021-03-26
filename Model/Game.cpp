#include "Model/Game.h"
#include "Model/Person.h"
#include "Model/ComputerAI.h"
#include "Model/Point.h"

#include <iostream>
#include <time.h>
#include <fstream>
#include <string.h>

Game::Game(int sizeSquareBoard, string playerType, string _nameAlgorithm)
{
    squareBoard = new SquareBoard(sizeSquareBoard);

    if(playerType.compare("person") == 0)
        player = new Person();
    else if(playerType.compare("computerAI") == 0)
        player = new ComputerAI(_nameAlgorithm, *squareBoard);
}

Game::Game(SquareBoard _squareBoard, string _playerType, int _moves)
{
    squareBoard = new SquareBoard(_squareBoard);

    if(_playerType.compare("person") == 0)
        player = new Person(_moves);
}

Game::Game(const Game& game)
{
    squareBoard = new SquareBoard(*game.squareBoard);

    if (typeid(*game.player) == typeid(Person))
        player = new Person(game.player->getMoves());
}

Game::~Game()
{
    delete squareBoard;
    delete player;
}

SquareBoard* Game::getSquareBoard() const
{
    return squareBoard;
}

Player* Game::getPlayer() const
{
    return player;
}

void Game::setSquareBoard(SquareBoard* _squareBoard)
{
    delete squareBoard;
    squareBoard = _squareBoard;
}

void Game::setPlayer(Player* _player)
{
    delete player;
    player = _player;
}

void Game::playGame()
{
    bool finishGameIs = false;
    NumberPuzzle *moveNumberPuzzle;

    while(!finishGameIs)
    {
        player->toString();
        squareBoard->printGameSquareBoard();

        if (typeid(*player) == typeid(Person))
        {
            bool correctMove;
            do{
                moveNumberPuzzle = new NumberPuzzle(*player->move(squareBoard->getGameNumberPuzzle(), 0));
                correctMove = checkCorrectMove(*moveNumberPuzzle);
                if(!correctMove)
                    cout << "Przesuniecie puzzla z numerem "<< moveNumberPuzzle->getNumber() << " jest niemozliwe" << endl;
            }while(!correctMove);
        }
        else if(typeid(*player) == typeid(ComputerAI))
        {
            moveNumberPuzzle = new NumberPuzzle(*player->move(squareBoard->getGameNumberPuzzle(), 0));
        }

        squareBoard->swapNumberPuzzleWithEmptyPuzzle(moveNumberPuzzle);
        player->increaseOneMoves();
        finishGameIs = checkIsGameEnd();
    }

    player->toString();
    squareBoard->printGameSquareBoard();
    cout << "KONIEC GRY" << endl;
}

int Game::playGameGUI(int _moveNumberPuzzleInt)
{
    NumberPuzzle *moveNumberPuzzle = nullptr;

    if (typeid(*player) == typeid(Person))
    {
        moveNumberPuzzle = new NumberPuzzle(*player->move(squareBoard->getGameNumberPuzzle(), _moveNumberPuzzleInt));
        bool correctMove = checkCorrectMove(*moveNumberPuzzle);
        if(!correctMove)
        {
//            cout << "Przesuniecie puzzla z numerem "<< moveNumberPuzzle->getNumber() << " jest niemozliwe" << endl;
            return -1;
        }
        else
        {
            squareBoard->swapNumberPuzzleWithEmptyPuzzle(moveNumberPuzzle);
            player->increaseOneMoves();
        }
    }
    else if(typeid(*player) == typeid(ComputerAI))
    {
        moveNumberPuzzle = new NumberPuzzle(*player->move(squareBoard->getGameNumberPuzzle(), _moveNumberPuzzleInt));
        squareBoard->swapNumberPuzzleWithEmptyPuzzle(moveNumberPuzzle);
        _moveNumberPuzzleInt = moveNumberPuzzle->getNumber();
        player->increaseOneMoves();
    }
//    squareBoard->printGameSquareBoard();
    return _moveNumberPuzzleInt;
}

int Game::playGamePreviousGUI()
{
    ComputerAI *computerAI;
    computerAI = dynamic_cast < ComputerAI*>( player );

    if( computerAI )
    {
        int numberPrevious = computerAI->movePrevious()->getNumber();
        NumberPuzzle *moveNumberPuzzle = nullptr;
        for(int i=0; i < squareBoard->getSize(); i++)
            for(int j=0; j < squareBoard->getSize(); j++)
                if(squareBoard->getGameNumberPuzzle()[i][j].getNumber() == numberPrevious)
                {
                    moveNumberPuzzle = new NumberPuzzle(numberPrevious, squareBoard->getGameNumberPuzzle()[i][j].getPoint() );
                    squareBoard->swapNumberPuzzleWithEmptyPuzzle(moveNumberPuzzle);
                    return numberPrevious;
                }
    }
    return -1;
}

void Game::resetGame()
{
    vector<int> startGame = squareBoard->getStartNumberPuzzle();
    player->setMoves(0);

    delete squareBoard;
    squareBoard = new SquareBoard(startGame, startGame);
}

bool Game::checkCorrectMove(NumberPuzzle numberPuzzleMove)
{
    int zeroX = squareBoard->getZeroNumberPuzzle()->getPoint()->getX();
    int zeroY = squareBoard->getZeroNumberPuzzle()->getPoint()->getY();

    int moveX = numberPuzzleMove.getPoint()->getX();
    int moveY = numberPuzzleMove.getPoint()->getY();

    if( ((zeroX - moveX) == 0 && ((zeroY - moveY) == 1 || (zeroY - moveY) == -1)) ||
        ((zeroY - moveY) == 0 && ((zeroX - moveX) == 1 || (zeroX - moveX) == -1))   )
        return true;
    else
        return false;
}

bool Game::checkIsGameEnd()
{
    vector<int> setupNumbersPuzzle;

    for(int i = 1; i < squareBoard->getSize() * squareBoard->getSize(); i++)
        setupNumbersPuzzle.push_back(i);
    setupNumbersPuzzle.push_back(0);

    vector<int>::iterator iterator = setupNumbersPuzzle.begin();
    bool returnValue = false;

    for(int i=0; i < squareBoard->getSize(); i++)
    {
        for(int j=0; j < squareBoard->getSize(); j++)
        {
            if(squareBoard->getGameNumberPuzzle()[i][j].getNumber() ==  *iterator)
            {
                returnValue = true;
            }
            else
            {
                returnValue = false;
                return returnValue;
            }
            iterator++;
        }
    }
    return returnValue;
}
