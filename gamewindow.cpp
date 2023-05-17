#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>

Gamewindow::Gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: lightgreen;");
    QPixmap granjero("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/agricultorFin.jpg");
    QPixmap plaga("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/Plaga.jpg");
    granjeroLab = findChild<QLabel*>("granjerolabel");
    granjeroLab->setPixmap(granjero);
    plagaLab = findChild<QLabel*>("plagalabel");
    plagaLab->setPixmap(plaga);
    granjeroLab->setGeometry(60,80,50,50);
    plagaLab->setGeometry(60,80,50,50);
    std::cout<<plagaLab->x()<<std::endl;
    generarLabels();
}

Gamewindow::~Gamewindow()
{
    delete ui;
}

void Gamewindow::generarLabels(){
    QGridLayout *layout = ui->gridLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    for (int x = 0; x < 8; x++) {
        for(int y = 0; y<8; y++){
            tablero[x][y] = new QLabel(this);
            //tablero[x][y]->setText("lola");
            tablero[x][y]->setStyleSheet("border: 1px solid black");
            //tablero[x][y]->QLineEdit(border: 1px solid white);
            layout->addWidget(tablero[x][y], x, y);
        }
    }
}

void Gamewindow::keyPressEvent( QKeyEvent * event)
{
    int py = granjeroLab->y();
    int px = granjeroLab->x();
    if( event->key() == Qt::Key_Down)
    {
        py += 77;
        granjeroLab->setGeometry(px,py,50,50);
    }
    else if( event->key() == Qt::Key_Up)
    {
        py -= 77;
        granjeroLab->setGeometry(px,py,50,50);
    }
    else if( event->key() == Qt::Key_Right)
    {
        px += 125;
        granjeroLab->setGeometry(px,py,50,50);
    }
    else if( event->key() == Qt::Key_Left)
    {
        px -= 125;
        granjeroLab->setGeometry(px,py,50,50);
    }
}
