#include "View/GamePage.h"

#include <QPainter>

GamePage::GamePage(QWidget *parent, int _size, vector<int> listNumbers, QString _typePlayer): QWidget(parent)
{
    typePlayer = _typePlayer;
    size = _size;
    setWindowTitle("Puzzle");
    setMinimumSize(600, 600);
    setMaximumSize(600, 600);
    mapper = new QSignalMapper( this );
    int index =0;

    game = new QPushButton** [_size];

    for (int i=0; i < _size ; i++)
    {
        game[i] = new QPushButton* [_size];
        for (int j=0; j < _size; j++)
        {
            if(listNumbers[index] != 0)
            {
                game[i][j] = new QPushButton(QString::number(listNumbers[index]), this);
                game[i][j]->setGeometry(geometry().width() / 2 - ((_size * 50 + _size * 5)/ 2) + (j * 50)+ j * 5,
                                        geometry().height() / 2 - ((_size * 50 + _size * 5)/ 2)+(i * 50) + i * 5,
                                        50, 50);

                QPalette pal= game[i][j]->palette();
                pal.setColor(QPalette::ButtonText, QColor(Qt::white));
                game[i][j]->setStyleSheet(""
                                "background-color: green;"
                                "border-radius: 10px;");
                game[i][j]->setPalette(pal);
                game[i][j]->setFont(QFont("Times", 20, QFont::Bold));


                connect(game[i][j], SIGNAL(clicked()), mapper, SLOT(map()));
                mapper->setMapping(game[i][j], QString::number(listNumbers[index]));
            }
            else
            {
                game[i][j] = new QPushButton();
                game[i][j]->setGeometry(geometry().width() / 2 - ((_size * 50 + _size * 5)/ 2)+(j * 50) + j * 5,
                                        geometry().height() / 2 - ((_size * 50 + _size * 5)/ 2)+(i * 50) + i * 5,
                                        50, 50);

                connect(game[i][j], SIGNAL(clicked()), mapper, SLOT(map()));
                mapper->setMapping(game[i][j],QString::number(listNumbers[index]));
            }
            index++;
        }
    }
    titleMoves = new QLabel("Moves:", this);
    titleMoves->setGeometry(game[0][0]->x(),  game[0][0]->y() - 50, 70, 30);
    titleMoves->setFont(QFont("Times", 14, QFont::Bold));

    lcdNumber = new QLCDNumber(this);
    lcdNumber->setGeometry(game[0][0]->x() + 70,  game[0][0]->y() - 50, 80, 30);


    if(_typePlayer.compare("Człowiek") == 0)
    {
        action1 = new QPushButton("Resetuj", this);
        action1->setGeometry(game[size-1][0]->x(), game[size-1][0]->y() + 50, 100, 50);

        action2 = new QPushButton("Zapisz", this);
        action2->setGeometry(game[size-1][0]->x()+ 150, game[size-1][0]->y() + 50, 100, 50);
    }
    else
    {
        action1 = new QPushButton("Poprzedni", this);
        action1->setGeometry(game[size-1][0]->x(), game[size-1][0]->y() + 50, 100, 50);
        action1->setEnabled(false);

        action2 = new QPushButton("Następny", this);
        action2->setGeometry(game[size-1][0]->x()+ 150, game[size-1][0]->y() + 50, 100, 50);
    }

}

GamePage::~GamePage()
{
    for (int i=0; i < size ; i++)
        for (int j=0; j < size; j++)
            delete game[i][j];

    for (int i = 0; i< size; i++)
            delete [] game[i];

    delete [] game;
    delete lcdNumber;
    delete titleMoves;
    delete action1;
    delete action2;
    delete mapper;
}

QPushButton*** GamePage::getGameBoard() const
{
    return game;
}

QSignalMapper* GamePage::getSignalMapper() const
{
    return mapper;
}

QPushButton* GamePage::getAction1() const
{
    return action1;
}

QPushButton* GamePage::getAction2() const
{
    return action2;
}

QLCDNumber* GamePage::getLCDNumber() const
{
    return lcdNumber;
}

QString GamePage::getTypePlayer() const
{
    return typePlayer;
}

void GamePage::paintEvent(QPaintEvent *e)
{   
    QPainter painter = QPainter(this);

    for (int i=0; i < size ; i++)
    {
        for (int j=0; j < size; j++)
        {
            QRect rec(geometry().width() / 2 - (size * 50 + size * 5)/ 2 + (j * 50) + j * 5, geometry().height() / 2 - (size * 50 + size * 5)/ 2 +(i * 50) + i * 5, 50, 50);
            painter.fillRect(rec,Qt::darkGray);
        }
    }
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(66, 66);
}
