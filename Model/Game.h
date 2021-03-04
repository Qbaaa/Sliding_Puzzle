#ifndef GAME_H
#define GAME_H

class SaveLoad;
class SquareBoard;
class Player;

class Game{

private:
    SquareBoard *squareBoard;
    Player *player;
    SaveLoad *saveLoad;

public:
    Game();
    ~Game();

    SquareBoard* getSquareBoard() const;
    Player* getPlayer() const;
    SaveLoad* getSaveLoad() const;
    void setSquareBoard(SquareBoard* _squareBoard);
    void setPlayer(Player* _player);
    void setSaveLoad(SaveLoad* _saveLoad);

    void playGame();
    bool checkIsGameEnd();

};

#endif // GAME_H
