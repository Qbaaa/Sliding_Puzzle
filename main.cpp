#include "View/GUI.h"
#include "Model/ComputerAI.h"
#include "Model/Game.h"
#include "Model/SquareBoard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI w;
    return app.exec();
}
