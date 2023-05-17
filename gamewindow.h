#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "qlabel.h"
#include <QPixmap>
#include <QKeyEvent>

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
    explicit Gamewindow(QWidget *parent = nullptr);
    QLabel *tablero[8][8];
    QLabel* granjeroLab;
    QLabel* plagaLab;
    void generarLabels();
    void keyPressEvent( QKeyEvent * event);
    ~Gamewindow();

private:
    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
