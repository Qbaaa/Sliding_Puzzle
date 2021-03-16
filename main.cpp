#include "View/mainwindow.h"
#include "Model/ComputerAI.h"
#include "Model/Game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    //Game test(3, "computerAI");
    //test.playGame();
    return app.exec();
}
