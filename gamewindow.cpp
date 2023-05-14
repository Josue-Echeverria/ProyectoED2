#include "gamewindow.h"
#include "ui_gamewindow.h"

Gamewindow::Gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);
}

Gamewindow::~Gamewindow()
{
    delete ui;
}
