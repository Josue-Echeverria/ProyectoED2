#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "qlabel.h"
#include <QPixmap>
#include <QKeyEvent>
#include "granjero.h"
#include "plagaThread.h"
#include "tablero.h"
#include <iostream>
#include "mainwindow.h"
#include <QMutex>

namespace Ui {
class Gamewindow;
}
class Gamewindow : public QDialog
{
    Q_OBJECT
    MainWindow *main_window;

public:
    explicit Gamewindow(QWidget *parent = nullptr, MainWindow *m = NULL);
    QLabel *parcelas[8][8];
    QLabel* granjeroLab;
    QLabel* plagaLab;
    QLabel * ovejaLab;
    QLabel * cuervoLab;
    granjero * granjeroTab;
    plagaThread * plagahilo;
    plagaThread * ovejahilo;
    plagaThread * cuervohilo;
    tablero * tab;
    QMutex * mutexTablero;
    void generarLabels();
    void keyPressEvent( QKeyEvent * event);
    void verificarGranjero(int x, int y);
  ~Gamewindow();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:


    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
