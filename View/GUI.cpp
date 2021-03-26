#include "GUI.h"
#include <iostream>

#include <QFileDialog>
#include <QMessageBox>
#include <QPropertyAnimation>

#include <Model/ComputerAI.h>

GUI::GUI()
    : QDialog()
{
    pages = new QStackedWidget();
    pages->addWidget( mainPage = new MainPage( pages ) );
    pages->addWidget( selectPage = new SelectPage( pages ) );
    pages->addWidget( gamePage = new GamePage( pages ) );
    pages->show();

    connect(mainPage->getBNewGame(), SIGNAL(clicked()), this, SLOT(doSelectPage()));
    connect(mainPage->getBExit(), SIGNAL(clicked()), this, SLOT(doExit()));
    connect(mainPage->getBLoad(), SIGNAL(clicked()), this, SLOT(doLoadGame()));

    connect(selectPage->getSelectTypeGame(), SIGNAL(currentTextChanged(const QString&)), this, SLOT(doSelectTypePlayer(const QString&)));
    connect(selectPage->getBStart(), SIGNAL(clicked()), this, SLOT(doStart()));
    connect(selectPage->getBMainPage(), SIGNAL(clicked()), this, SLOT(doMainPage()));

    controller = new ControllerGame();
}

GUI::~GUI()
{
    delete pages;
    delete controller;
}

void GUI::doSelectPage()
{
  pages->setCurrentIndex( pages->currentIndex()+1 );
}

void GUI::doExit()
{
    pages->close();
}

void GUI::doLoadGame()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Load Game Puzzle"), "",
          tr("Puzzle (Puzzle*.dat)"));

    if (fileName.isEmpty())
        return;
    else
    {
        if( controller->handleLoad(fileName.toStdString()))
        {
            pages->removeWidget(gamePage);
            delete gamePage;

            vector<int> listNumbers;
            for(int i=0; i < controller->getGame()->getSquareBoard()->getSize(); i++)
                for(int j=0; j < controller->getGame()->getSquareBoard()->getSize(); j++)
                    listNumbers.push_back(controller->getGame()->getSquareBoard()->getGameNumberPuzzle()[i][j].getNumber());

            pages->addWidget( gamePage = new GamePage( pages,
                                                           controller->getGame()->getSquareBoard()->getSize() ,
                                                           listNumbers, "Człowiek" ) );

            gamePage->getLCDNumber()->display(controller->getGame()->getPlayer()->getMoves());

            connect(gamePage->getSignalMapper(), SIGNAL(mappedString(const QString&)), this, SLOT(doMovePuzzle(const QString&)));
            connect(gamePage->getAction1(), SIGNAL(clicked()), this, SLOT(doAction1()));
            connect(gamePage->getAction2(), SIGNAL(clicked()), this, SLOT(doAction2()));
            pages->setCurrentWidget( gamePage );
        }
        else
            QMessageBox::warning(this, tr("Układanka"), tr("Nie udało sie wczytać gry.\n"));
    }
}

void GUI::doSelectTypePlayer(const QString &text)
{
    if(text.compare("Komputer") == 0)
        selectPage->getSelectTypeAlgorithm()->setEnabled(true);
    else
        selectPage->getSelectTypeAlgorithm()->setEnabled(false);
}

void GUI::doStart()
{
    pages->removeWidget(gamePage);
    delete gamePage;
    if(selectPage->getSelectTypeGame()->currentText().compare("Komputer") == 0)
    {
        controller->handleStart(selectPage->getSelectTypeSize()->currentText().toInt(),
                                "computerAI",
                                selectPage->getSelectTypeAlgorithm()->currentText().toStdString());
        pages->addWidget( gamePage = new GamePage( pages,
                                                   selectPage->getSelectTypeSize()->currentText().toInt(),
                                                   controller->getGame()->getSquareBoard()->getStartNumberPuzzle(), "Komputer") );
    }
    else
    {
        controller->handleStart(selectPage->getSelectTypeSize()->currentText().toInt(),
                                "person",
                                selectPage->getSelectTypeAlgorithm()->currentText().toStdString());
        pages->addWidget( gamePage = new GamePage( pages,
                                                   selectPage->getSelectTypeSize()->currentText().toInt(),
                                                   controller->getGame()->getSquareBoard()->getStartNumberPuzzle(), "Człowiek" ) );
        connect(gamePage->getSignalMapper(), SIGNAL(mappedString(const QString&)), this, SLOT(doMovePuzzle(const QString&)));
    }
    connect(gamePage->getAction1(), SIGNAL(clicked()), this, SLOT(doAction1()));
    connect(gamePage->getAction2(), SIGNAL(clicked()), this, SLOT(doAction2()));
    pages->setCurrentWidget( gamePage );
}

void GUI::doMainPage()
{
    pages->setCurrentIndex(pages->currentIndex()-1);
}

void GUI::doMovePuzzle(const QString &numberPuzzle)
{
    if( controller->handleMovePuzzle(numberPuzzle.toInt()) != -1)
    {
        QPushButton *numberPuzzleMove = (QPushButton *)gamePage->getSignalMapper()->mapping(numberPuzzle);

        QPropertyAnimation *animation = new QPropertyAnimation(numberPuzzleMove, "geometry");
        animation->setDuration(200);
        QRect startAnimation = QRect(numberPuzzleMove->geometry().x(), numberPuzzleMove->geometry().y(),
                                     numberPuzzleMove->geometry().width(), numberPuzzleMove->geometry().height());
        animation->setStartValue(startAnimation);

        QPushButton *NumberPuzzleEmpty = (QPushButton *)gamePage->getSignalMapper()->mapping("0");
        QRect endAnimation = QRect(NumberPuzzleEmpty->geometry().x(), NumberPuzzleEmpty->geometry().y(),
                                   NumberPuzzleEmpty->geometry().width(), NumberPuzzleEmpty->geometry().height());
        animation->setEndValue(endAnimation);
        animation->start();
        NumberPuzzleEmpty->setGeometry(startAnimation);

        gamePage->getLCDNumber()->display(controller->getGame()->getPlayer()->getMoves());

        if( controller->getGame()->checkIsGameEnd() )
        {
            for (int i=0; i < controller->getGame()->getSquareBoard()->getSize() ; i++)
                for (int j=0; j < controller->getGame()->getSquareBoard()->getSize(); j++)
                    gamePage->getGameBoard()[i][j]->setEnabled(false);

            QMessageBox::information(this, tr("Układanka"), tr("Koniec gry.\n"));

            gamePage->getAction2()->setEnabled(false);
        }
    }
}

void GUI::doAction1()
{
    if(gamePage->getTypePlayer().compare("Człowiek") == 0)
    {
        controller->handleReset();
        vector<int> listNumbers;
        for(int i=0; i < controller->getGame()->getSquareBoard()->getSize(); i++)
            for(int j=0; j < controller->getGame()->getSquareBoard()->getSize(); j++)
                listNumbers.push_back(controller->getGame()->getSquareBoard()->getGameNumberPuzzle()[i][j].getNumber());

        pages->removeWidget(gamePage);
        delete gamePage;

        pages->addWidget( gamePage = new GamePage( pages, controller->getGame()->getSquareBoard()->getSize(), listNumbers, "Człowiek" ) );

        gamePage->getLCDNumber()->display(controller->getGame()->getPlayer()->getMoves());
        connect(gamePage->getSignalMapper(), SIGNAL(mappedString(const QString&)), this, SLOT(doMovePuzzle(const QString&)));
        connect(gamePage->getAction1(), SIGNAL(clicked()), this, SLOT(doAction1()));
        connect(gamePage->getAction2(), SIGNAL(clicked()), this, SLOT(doAction2()));
        pages->setCurrentWidget( gamePage );
    }
    else
    {
        string movePreviousNumber = to_string(controller->handlePreviousComputer());
        //controller->getGame()->getSquareBoard()->printGameSquareBoard();

        QString qMovePreviousNumber = QString::fromStdString(movePreviousNumber);
        QPushButton *numberPuzzleMove = (QPushButton *)gamePage->getSignalMapper()->mapping(qMovePreviousNumber);

        QPropertyAnimation *animation = new QPropertyAnimation(numberPuzzleMove, "geometry");
        animation->setDuration(200);
        QRect startAnimation = QRect(numberPuzzleMove->geometry().x(), numberPuzzleMove->geometry().y(),
                                         numberPuzzleMove->geometry().width(), numberPuzzleMove->geometry().height());
        animation->setStartValue(startAnimation);

        QPushButton *NumberPuzzleEmpty = (QPushButton *)gamePage->getSignalMapper()->mapping("0");
        QRect endAnimation = QRect(NumberPuzzleEmpty->geometry().x(), NumberPuzzleEmpty->geometry().y(),
                                       NumberPuzzleEmpty->geometry().width(), NumberPuzzleEmpty->geometry().height());
        animation->setEndValue(endAnimation);
        animation->start();
        NumberPuzzleEmpty->setGeometry(startAnimation);

        gamePage->getLCDNumber()->display(controller->getGame()->getPlayer()->getMoves());

        if( controller->getGame()->getPlayer()->getMoves() == 0 )
        {
            gamePage->getAction1()->setEnabled(false);
        }
        gamePage->getAction2()->setEnabled(true);
    }
}

void GUI::doAction2()
{
    if(gamePage->getTypePlayer().compare("Człowiek") == 0)
    {
        if (controller->handleSave())
            QMessageBox::information(this, tr("Układanka"), tr("Poprawnie zapisano grę.\n"));
        else
            QMessageBox::warning(this, tr("Układanka"), tr("Nie udało sie zapisać gry.\n"));
    }
    else
    {
        string moveNumber = to_string(controller->handleNextComputer());
        QString qMoveNumber = QString::fromStdString(moveNumber);
        QPushButton *numberPuzzleMove = (QPushButton *)gamePage->getSignalMapper()->mapping(qMoveNumber);

        QPropertyAnimation *animation = new QPropertyAnimation(numberPuzzleMove, "geometry");
        animation->setDuration(200);
        QRect startAnimation = QRect(numberPuzzleMove->geometry().x(), numberPuzzleMove->geometry().y(),
                                         numberPuzzleMove->geometry().width(), numberPuzzleMove->geometry().height());
        animation->setStartValue(startAnimation);

        QPushButton *NumberPuzzleEmpty = (QPushButton *)gamePage->getSignalMapper()->mapping("0");
        QRect endAnimation = QRect(NumberPuzzleEmpty->geometry().x(), NumberPuzzleEmpty->geometry().y(),
                                       NumberPuzzleEmpty->geometry().width(), NumberPuzzleEmpty->geometry().height());
        animation->setEndValue(endAnimation);
        animation->start();
        NumberPuzzleEmpty->setGeometry(startAnimation);

        gamePage->getLCDNumber()->display(controller->getGame()->getPlayer()->getMoves());

        if( controller->getGame()->checkIsGameEnd() )
        {
            gamePage->getAction2()->setEnabled(false);
        }
        gamePage->getAction1()->setEnabled(true);
    }
}
