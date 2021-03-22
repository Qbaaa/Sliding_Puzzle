#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "View/GUI.h"

#include <QLabel>
#include <QPushButton>
#include <QWidget>

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
};

#endif // MAINPAGE_H
