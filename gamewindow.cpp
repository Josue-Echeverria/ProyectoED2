#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMainWindow>
#include <QHideEvent>
#include <QDebug>

Gamewindow::Gamewindow(QWidget *parent, MainWindow *mw):
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);
    this->show();
    this->main_window  = mw;
    this->main_window->show();


}

Gamewindow::~Gamewindow()
{
    delete ui;
}
