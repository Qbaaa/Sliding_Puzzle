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
    Model/NodeBoard.cpp \
    Model/NumberPuzzle.cpp \
    Model/Person.cpp \
    Model/Player.cpp \
    Model/SquareBoard.cpp \
    View/GUI.cpp \
    View/GamePage.cpp \
    View/MainPage.cpp \
    View/SelectPage.cpp \
    main.cpp \

HEADERS += \
    Model/ComputerAI.h \
    Model/File.h \
    Model/Game.h \
    Model/NodeBoard.h \
    Model/NumberPuzzle.h \
    Model/Person.h \
    Model/Player.h \
    Model/Point.h \
    Model/SquareBoard.h \
    View/GUI.h \
    View/GamePage.h \
    View/MainPage.h \
    View/SelectPage.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
