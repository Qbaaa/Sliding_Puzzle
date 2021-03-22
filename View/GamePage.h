#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>

class GamePage :public QWidget
{
private:
    QPushButton ***game;
    QSignalMapper *mapper;
    QPushButton *action1;
    QPushButton *action2;
    QLabel *titleMoves;
    QLCDNumber *lcdNumber;
    int size;
    QString typePlayer;

public:
    GamePage(QWidget *parent= nullptr, int _size= 3, QString _typePlayer= "Człowiek");
    ~GamePage();

    void paintEvent(QPaintEvent *e);

};

#endif // GAMEPAGE_H
