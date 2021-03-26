#ifndef GUI_H
#define GUI_H

#include "View/MainPage.h"
#include "View/SelectPage.h"
#include "View/GamePage.h"
#include "Controller/ControllerGame.h"

#include <QDialog>
#include <QStackedWidget>

class MainPage;
class SelectPage;

/**
* Klasa GUI jest przeznaczona zarządzania graficznymi interfejsami użytkownika w Qt
*/
class GUI : public QDialog
{
    Q_OBJECT
private:
  QStackedWidget *pages;
  MainPage *mainPage;
  SelectPage *selectPage;
  GamePage *gamePage;

  ControllerGame *controller;

public:
    GUI();
    ~GUI();

private slots:
    void doSelectPage();
    void doLoadGame();
    void doExit();

    void doSelectTypePlayer(const QString &text);
    void doStart();
    void doMainPage();

     void doMovePuzzle(const QString &numberPuzzle);
     void doAction1();
     void doAction2();
};

#endif // GUI_H
