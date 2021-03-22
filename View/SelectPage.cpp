#include "View/SelectPage.h"

SelectPage::SelectPage(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Puzzle");
    setMinimumSize(600, 600);
    setMaximumSize(600,600);

    title = new QLabel("Układanka", this);
    title->setGeometry(150, 20,300, 159);
    title->setFont(QFont("Times", 25, QFont::Bold));
    title->setAlignment(Qt::AlignCenter);

    titleTypeGame = new QLabel("Typ Gracza:", this);
    titleTypeGame->setGeometry(150, 180, 120, 30);
    titleTypeGame->setFont(QFont("Times", 14, QFont::Bold));
    titleTypeGame->setAlignment(Qt::AlignRight);

    selectTypeGame = new QComboBox(this);
    selectTypeGame->addItem("Człowiek");
    selectTypeGame->addItem("Komputer");
    selectTypeGame->setGeometry(270, 180, 150, 25);

    titleTypeAlgorithm = new QLabel("Algorytm:", this);
    titleTypeAlgorithm->setGeometry(150, 230, 120, 30);
    titleTypeAlgorithm->setFont(QFont("Times", 14, QFont::Bold));
    titleTypeAlgorithm->setAlignment(Qt::AlignRight);

    selectTypeAlgorithm = new QComboBox(this);
    selectTypeAlgorithm->addItem("A*");
    selectTypeAlgorithm->addItem("IDA*");
    selectTypeAlgorithm->setGeometry(270, 230, 150, 25);
    selectTypeAlgorithm->setEnabled(false);

    titleTypeSize = new QLabel("Rozmiar:", this);
    titleTypeSize->setGeometry(150, 280, 120, 30);
    titleTypeSize->setFont(QFont("Times", 14, QFont::Bold));
    titleTypeSize->setAlignment(Qt::AlignRight);

    selectTypeSize = new QComboBox(this);
    selectTypeSize->addItem("3");
    selectTypeSize->addItem("4");
    selectTypeSize->addItem("5");
    selectTypeSize->addItem("6");
    selectTypeSize->setGeometry(270, 280, 150, 25);

    bStart = new QPushButton("Start", this);
    bStart->setGeometry(200, 330, 200, 50);

}

SelectPage::~SelectPage()
{
    delete title;
    delete titleTypeGame;
    delete titleTypeAlgorithm;
    delete titleTypeSize;
    delete selectTypeGame;
    delete selectTypeAlgorithm;
    delete selectTypeSize;
    delete bStart;
}
