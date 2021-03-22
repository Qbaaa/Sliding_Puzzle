#include "GUI.h"
#include <iostream>

GUI::GUI()
    : QDialog()
{
    pages = new QStackedWidget();
    pages->addWidget( mainPage = new MainPage( pages ) );
    pages->addWidget( selectPage = new SelectPage( pages ) );
    pages->addWidget( gamePage = new GamePage( pages, 4, "Komputer" ) );
    pages->show();
}

GUI::~GUI()
{
    delete pages;
}

