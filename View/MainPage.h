#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "View/GUI.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>

/**
* Klasa MainPage jest przeznaczona do modelowania graficznego interfejsu użytkownika w Qt
*
* Zadaniem klasy jest stworzenie widoku graficznego dla menu głównego układanki
* (przyciski: nowa gra, wczytaj grę, wyjdz z gry)
*/
class MainPage: public QWidget
{
private:
    QLabel *title;
    QPushButton *bNewGame;
    QPushButton *bLoad;
    QPushButton *bExit;

public:
    MainPage(QWidget *parent =nullptr);
    ~MainPage();

   QPushButton* getBNewGame() const;
   QPushButton* getBLoad() const;
   QPushButton* getBExit() const;
};

#endif // MAINPAGE_H
