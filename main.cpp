#include "View/mainwindow.h"
#include "Model/ComputerAI.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    SquareBoard b(vector<int>( {1,2,3,0,4,6,7,5,8}), vector<int>({0, 1, 3, 4, 2, 5, 7, 8, 6}) );
    ComputerAI ai("A*", b);
    return app.exec();
//    vector<int>({8, 1, 3, 4, 0, 2, 7, 6, 5}) ; ok
//    vector<int>({0, 1, 3, 4, 2, 5, 7, 8, 6}) ; ok
//    vector<int>({1, 2, 3, 4, 5, 6, 7, 0, 8}) ; ok
//    vector<int>({8, 1, 5, 4, 0, 6, 7, 2, 3}) ; ok
//    vector<int>({0, 1, 3, 4, 2, 5, 7, 8, 6}) ; ok
}
