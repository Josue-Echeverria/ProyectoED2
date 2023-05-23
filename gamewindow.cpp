#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>

Gamewindow::Gamewindow(QWidget *parent,MainWindow *m):
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
        ui->setupUi(this);

    this->main_window = m;
    this->setStyleSheet("background-color: lightgreen;");
    QPixmap granjero("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/agricultorFin.png");
    QPixmap plaga("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/Plaga.png");
    granjeroLab = findChild<QLabel*>("granjeroLabel");
    QPixmap oveja("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/oveja.png");
    QPixmap cuervo("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/cuervo.png");
    //QPixmap espantapajaro("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/espantapajaros.jpg");
    granjeroLab->setPixmap(granjero);
    plagaLab = findChild<QLabel*>("plagaLabel");
    plagaLab->setPixmap(plaga);
    plagaLab->setVisible(false);
    ovejaLab = findChild<QLabel*>("ovejaLabel");
    ovejaLab->setPixmap(oveja);
    ovejaLab->setVisible(false);
    cuervoLab = findChild<QLabel*>("cuervoLabel");
    cuervoLab->setPixmap(cuervo);
    cuervoLab->setVisible(false);
    tab = new class tablero();
    granjeroTab = new class granjero(granjeroLab, tab);
    granjeroTab->cargaEspantajaros = true;
    plagahilo = new plagaThread(plagaLab, 100, 2, 5, 0, 0, 3, tab, granjeroTab, mutexTablero);
    ovejahilo = new plagaThread(ovejaLab, 100, 1, 5, 0, 0, 1, tab, granjeroTab, mutexTablero);
    cuervohilo = new plagaThread(cuervoLab, 100, 1, 5, 0, 0, 1, tab, granjeroTab, mutexTablero);
    granjeroLab->setGeometry(60,80,50,50);
    plagaLab->setGeometry(60,80,50,50);
    std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<std::endl;
    std::cout<<plagaLab->x()<<std::endl;
    generarLabels();
    cuervohilo->start();
    plagahilo->start();
    ovejahilo->start();
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




void Gamewindow::keyPressEvent(QKeyEvent * event)
{
    int py = granjeroLab->y();
    int px = granjeroLab->x();
    if( event->key() == Qt::Key_Down)
    {
        py += 77;
        if(py > 619)
            py = 80;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_Up)
    {
        py -= 77;
        if(py < 80)
            py = 619;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_Right)
    {
        px += 125;
        if(px > 935)
            px = 60;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_Left)
    {
        px -= 125;
        if(px < 60)
            px = 935;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_F1){
        this->main_window->show();
    }
    else if(event->key() == Qt::Key_F4){
        if(granjeroTab->cargaEspantajaros){
            QPixmap espantapajaro("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/espantapajaros.png");
            int posy_matriz = (py-80)/77;
            int posx_matriz = (px-60)/125;
            tab->Tablero[posx_matriz][posy_matriz]->espantaPaj = true;
            parcelas[posy_matriz][posx_matriz]->setPixmap(espantapajaro);
            //granjeroTab->cargaEspantajaros = false;
        }
    }
}

void Gamewindow::verificarGranjero(int x, int y){
    if(plagaLab->x() == x && plagaLab->y() == y){
        plagaLab->setVisible(false);
    }
    else if(ovejaLab->x() == x && ovejaLab->y() == y){
        ovejaLab->setVisible(false);
    }
    else if(cuervoLab->x() == x && cuervoLab->y() == y){
        cuervoLab->setVisible(false);
    }
}

void Gamewindow::on_pushButton_clicked()
{

}


void Gamewindow::on_pushButton_2_clicked()
{

}

