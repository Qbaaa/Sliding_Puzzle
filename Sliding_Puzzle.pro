QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

TEMPLATE =app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/ComputerAI.cpp \
    Model/File.cpp \
    Model/Game.cpp \
    Model/NumberPuzzle.cpp \
    Model/Person.cpp \
    Model/Player.cpp \
    Model/SquareBoard.cpp \
    View/mainwindow.cpp \
    main.cpp \

HEADERS += \
    Model/ComputerAI.h \
    Model/File.h \
    Model/Game.h \
    Model/NumberPuzzle.h \
    Model/Person.h \
    Model/Player.h \
    Model/Point.h \
    Model/SquareBoard.h \
    View/mainwindow.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
