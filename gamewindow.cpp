#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>


Gamewindow::Gamewindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: lightgreen;");
    QPixmap granjero("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/agricultorFin.jpg");
    QPixmap plaga("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/Plaga.jpg");
    QPixmap oveja("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/oveja.png");
    QPixmap cuervo("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/cuervo.jpg");
    granjeroLab = findChild<QLabel*>("granjeroLabel");
    granjeroLab->setPixmap(granjero);
    plagaLab = findChild<QLabel*>("plagaLabel");
    plagaLab->setPixmap(plaga);
    plagaLab->setVisible(false);
    ovejaLab = findChild<QLabel*>("ovejaLabel");
    ovejaLab->setPixmap(oveja);
    cuervoLab = findChild<QLabel*>("cuervoLabel");
    cuervoLab->setPixmap(cuervo);
    tab = new class tablero();
    plagahilo = new plagaThread(plagaLab, 100, 2, 5, 0, 0, 1, tab);
    //ovejahilo = new plagaThread(plagaLab, 100, 1, 10, 0, 0, 1, tab);
    //plagahilo = new plagaThread(plagaLab, 100, 1, 10, 0, 0, 1, tab);
    granjeroLab->setGeometry(60,80,50,50);
    plagaLab->setGeometry(60,80,50,50);
    generarLabels();
    plagahilo->start();
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
            parcelas[x][y] = new QLabel(this);
            //tablero[x][y]->setText("lola");
            parcelas[x][y]->setStyleSheet("border: 1px solid black");
            //tablero[x][y]->QLineEdit(border: 1px solid white);
            layout->addWidget(parcelas[x][y], x, y);
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
        if(py > 619)
            py = 80;
        granjeroLab->setGeometry(px,py,50,50);

    }
    else if( event->key() == Qt::Key_Up)
    {
        py -= 77;
        if(py < 80)
            py = 619;
        granjeroLab->setGeometry(px,py,50,50);
    }
    else if( event->key() == Qt::Key_Right)
    {
        px += 125;
        if(px > 935)
            px = 60;
        granjeroLab->setGeometry(px,py,50,50);
    }
    else if( event->key() == Qt::Key_Left)
    {
        px -= 125;
        if(px < 60)
            px = 935;
        granjeroLab->setGeometry(px,py,50,50);
    }
}
