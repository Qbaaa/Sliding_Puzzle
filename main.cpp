#include "View/GUI.h"
#include "Model/ComputerAI.h"
#include "Model/Game.h"
#include "Model/SquareBoard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI w;
    //SquareBoard s(vector<int>({1, 2, 3, 4, 5, 7, 10, 11, 9, 6, 13, 12, 8, 15, 14, 0}),
    //                       vector<int>({1, 2, 3, 4, 5, 7, 10, 11, 9, 6, 8, 12, 13, 15, 14, 0}));
    //ComputerAI a("IDA*", s);
    //Game test(3, "computerAI");
    //test.playGame();
    return app.exec();
}
