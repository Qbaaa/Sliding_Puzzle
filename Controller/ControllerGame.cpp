#include "Controller/ControllerGame.h"
#include "Model/File.h"

ControllerGame::ControllerGame()
{
    game = nullptr;
}

ControllerGame::~ControllerGame()
{
     delete game;
}

Game* ControllerGame::getGame() const
{
    return game;
}

bool ControllerGame::handleLoad(string fileName)
{
    File file = File();
    list<Game> loadGame = file.load(fileName);
    if(loadGame.empty())
        return false;
    else
    {
        delete game;
        game = new Game(*loadGame.begin());
        return true;
    }
}

void ControllerGame::handleStart(int _size, string _typePalyer, string _typeAlgorithm)
{
    delete game;
    game = new Game(_size, _typePalyer, _typeAlgorithm);
}

bool ControllerGame::handleSave()
{
    File file = File();
    return file.save(game);

}

int ControllerGame::handleMovePuzzle(int movePuzzle)
{
   return( game->playGameGUI(movePuzzle) );
}

void ControllerGame::handleReset()
{
    game->resetGame();
}

int ControllerGame::handleNextComputer()
{
    return game->playGameGUI(-1);
}

int ControllerGame::handlePreviousComputer()
{
    return game->playGamePreviousGUI();
}
