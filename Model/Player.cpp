#include "Player.h"

Player::Player(): moves(0){}

Player::Player(int _moves): moves(_moves){}

Player::~Player(){}

int Player::getMoves() const
{
    return moves;
}

void Player::setMoves(int _moves)
{
    moves = _moves;
}

void Player::increaseOneMoves()
{
    moves++;
}
