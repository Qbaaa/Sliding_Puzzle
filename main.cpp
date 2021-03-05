#include "View/mainwindow.h"

#include <QApplication>

#include <Model/Game.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    Game game(2, "person");
    game.playGame();
    return app.exec();
}
