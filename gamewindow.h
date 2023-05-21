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
namespace Ui {
class Gamewindow;
}
class Gamewindow : public QDialog
{
    Q_OBJECT
    MainWindow *main_window;

public:
    explicit Gamewindow(QWidget *parent = nullptr);
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
    void generarLabels();
    void keyPressEvent( QKeyEvent * event);
    ~Gamewindow();

private:
    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
