#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include <iostream>
namespace Ui {
class Gamewindow;
}
class Gamewindow : public QDialog
{
    Q_OBJECT
    MainWindow *main_window;

public:
    Gamewindow(QWidget *parent = nullptr, MainWindow *mw = NULL);
    ~Gamewindow();

private:
    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
