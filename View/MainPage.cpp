#include "View/MainPage.h"

MainPage::MainPage(QWidget *parent): QWidget(parent)
{
    parent->setWindowTitle("Puzzle");
    parent->setMinimumSize(600, 600);
    parent->setMaximumSize(600,600);

    title = new QLabel("Układanka", this);
    bNewGame = new QPushButton("Nowa Gra", this);
    bLoad = new QPushButton("Wczytaj" ,this);
    bExit = new QPushButton("Wyjdż", this);

    title->setGeometry(150, 20, 300, 159);
    bNewGame->setGeometry(200, 200, 200, 50);
    bLoad->setGeometry(200, 275, 200, 50);
    bExit->setGeometry(200, 350, 200, 50);

    title->setFont(QFont("Times", 25, QFont::Bold));
    title->setAlignment(Qt::AlignCenter);
}

MainPage::~MainPage()
{
    delete title;
    delete bNewGame;
    delete bLoad;
    delete bExit;
}
