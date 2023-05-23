#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int *cost_abb ,int *cost_avl ,int *cost_arj ,int *cost_heap ,
                       int *t_cres_abb ,int *t_cres_avl ,int *t_cres_arj ,int *t_cres_heap ,
                       int *cos_abb ,int *cos_avl ,int *cos_arj ,int *cos_heap ,
                       int *tcos_abb ,int *tcos_avl ,int *tcos_arj ,int *tcos_heap ,
                       double *prec_fru_abb ,double *prec_fru_avl ,double *prec_fru_arj ,double *prec_fru_heap,
                       int *costo_espantapajaros)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->costo_espantapajaros = costo_espantapajaros;

    this->costo_abb = cost_abb;
    this->cosecha_abb = cos_abb;
    this->cosecha_cada_t_abb = tcos_abb;
    this->precio_frut_abb = prec_fru_abb;
    this->t_crecimien_abb = t_cres_abb;

    this->costo_avl = cost_avl;
    this->cosecha_avl = cos_avl;
    this->cosecha_cada_t_avl = tcos_avl;
    this->precio_frut_avl = prec_fru_avl;
    this->t_crecimien_avl = t_cres_avl;

    this->cosecha_arj = cos_arj;
    this->cosecha_cada_t_arj = tcos_arj;
    this->precio_frut_arj = prec_fru_arj;
    this->costo_arj = cost_arj;
    this->t_crecimien_arj = t_cres_arj;

    this->cosecha_heap = cos_heap;
    this->cosecha_cada_t_heap = tcos_heap;
    this->precio_frut_heap = prec_fru_heap;
    this->costo_heap = cost_heap;
    this->t_crecimien_heap = t_cres_heap;

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_guardar_clicked()
{
    int arbol_index = findChild<QComboBox*>("comboBox_arboles")->currentIndex();
    QString a= findChild<QLineEdit*>("lineEdit_cost")->text();
    QString b= findChild<QLineEdit*>("lineEdit_cosecha")->text();
    QString c= findChild<QLineEdit*>("lineEdit_t_cosecha")->text();
    QString d= findChild<QLineEdit*>("lineEdit_price")->text();
    QString f= findChild<QLineEdit*>("lineEdit_price_2")->text();
    QString e= findChild<QLineEdit*>("lineEdit_t_crec")->text();

    double randomprice = QRandomGenerator::global()->bounded(d.toInt(), f.toInt()); // Generate random number between 50 and 100

    switch(arbol_index){

    case 0:

        *this->costo_abb = a.toInt();
        *this->cosecha_abb = b.toInt();
        *this->cosecha_cada_t_abb = c.toInt();
        *this->precio_frut_abb = randomprice;
        *this->t_crecimien_abb = e.toInt();
        break;

    case 1:

        *this->cosecha_avl = b.toInt();
        *this->costo_avl = a.toInt();
        *this->cosecha_cada_t_avl = c.toInt();
        *this->precio_frut_avl = randomprice;
        *this->t_crecimien_avl = e.toInt();
        break;

    case 2:

        *this->costo_arj = a.toInt();
        *this->cosecha_arj = b.toInt();
        *this->cosecha_cada_t_arj = c.toInt();
        *this->precio_frut_arj = randomprice;
        *this->t_crecimien_arj = e.toInt();
        break;

    case 3:

        *this->cosecha_heap = b.toInt();
        *this->cosecha_cada_t_heap = c.toInt();
        *this->precio_frut_heap = randomprice;
        *this->costo_heap = a.toInt();
        *this->t_crecimien_heap = e.toInt();
        break;
    }
}



void MainWindow::on_pButton_clicked()
{
    hide();
}

