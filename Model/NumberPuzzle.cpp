#include "Model/NumberPuzzle.h"
#include "Model/Point.h"

NumberPuzzle::NumberPuzzle(): number(0)
{
    point = new Point<int>();
}

NumberPuzzle::NumberPuzzle(int _number, Point<int> *_point): number(_number)
{
    point = new Point<int>(*_point);
}

NumberPuzzle::~NumberPuzzle()
{
    delete point;
}

int NumberPuzzle::NumberPuzzle::getNumber() const
{
    return number;
}

Point<int>* NumberPuzzle::getPoint() const
{
    return point;
}

void NumberPuzzle::setNumber(int _number)
{
    number = _number;
}

void NumberPuzzle::setPoint(Point<int> *_point)
{
    delete point;
    point = new Point<int>(*_point);
}
