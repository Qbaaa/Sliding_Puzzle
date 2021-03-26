#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QWidget>

/**
* Klasa SelectPage jest przeznaczona do modelowania graficznego interfejsu użytkownika w Qt
*
* Zadaniem klasy jest stworzenie widoku graficznego dla wyboru parametrów dla układanki
* (wybór gracza, algorytmu i rozmiaru planszy)
*/
class SelectPage: public QWidget
{
private:
    QLabel *title;
    QPushButton *bStart;
    QComboBox *selectTypeGame;
    QComboBox *selectTypeAlgorithm;
    QComboBox *selectTypeSize;
    QLabel *titleTypeGame;
    QLabel *titleTypeAlgorithm;
    QLabel *titleTypeSize;
    QPushButton *bMainPage;

public:
    SelectPage(QWidget *parent =nullptr);
    ~SelectPage();

    QPushButton* getBStart() const;
    QComboBox* getSelectTypeGame() const;
    QComboBox* getSelectTypeAlgorithm() const;
    QComboBox* getSelectTypeSize() const;
    QPushButton* getBMainPage() const;
};

#endif // SELECTPAGE_H
