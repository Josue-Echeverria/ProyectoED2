#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "gamewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pButton_clicked()
{
    Gamewindow game;
    game.setModal(true);
    hide();
    game.exec();

}

