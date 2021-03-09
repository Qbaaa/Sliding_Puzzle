#include "View/mainwindow.h"
#include <Model/File.h>
#include <Model/Game.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
