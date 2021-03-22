#ifndef GUI_H
#define GUI_H

#include "View/MainPage.h"
#include "View/SelectPage.h"
#include "View/GamePage.h"

#include <QDialog>
#include <QStackedWidget>

class MainPage;
class SelectPage;

class GUI : public QDialog
{
    Q_OBJECT
public:
  QStackedWidget *pages;
  MainPage *mainPage;
  SelectPage *selectPage;
  GamePage *gamePage;

public:
    GUI();
    ~GUI();
};
#endif // GUI_H
