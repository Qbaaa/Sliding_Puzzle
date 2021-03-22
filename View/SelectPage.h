#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QWidget>

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

public:
    SelectPage(QWidget *parent =nullptr);
    ~SelectPage();
};

#endif // SELECTPAGE_H
