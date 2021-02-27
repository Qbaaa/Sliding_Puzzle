#ifndef NUMBERPUZZLE_H
#define NUMBERPUZZLE_H

template <typename T>
class Point;

class NumberPuzzle{

private:
    int number;
    Point<int> *point;

public:
    NumberPuzzle();
    NumberPuzzle(int _number, Point<int> *_point);
    ~NumberPuzzle();
    int getNumber() const;
    Point<int>* getPoint() const;
    void setNumber(int _number);
    void setPoint(Point<int> *_point);

};

#endif // NUMBERPUZZLE_H
