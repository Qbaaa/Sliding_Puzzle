#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <vector>

using namespace std;

/**
* Klasa GamePage jest przeznaczona do modelowania graficznego interfejsu użytkownika w Qt
*
* Zadaniem klasy jest stworzenie widoku graficznego dla planszy kwadratowej wraz z polami
*/
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
    GamePage(QWidget *parent= nullptr, int _size= 3, vector<int> listNumbers={1,2,3,4,5,6,7,8,0}, QString _typePlayer= "Człowiek");
    ~GamePage();

    QPushButton *** getGameBoard() const;
    QSignalMapper* getSignalMapper() const;
    QPushButton* getAction1() const;
    QPushButton* getAction2() const;
    QLCDNumber* getLCDNumber() const;
    QString getTypePlayer() const;

    /**
    * Funkcja słuzy do rysowania obiektów
    */
    void paintEvent(QPaintEvent *e);
};

#endif // GAMEPAGE_H
