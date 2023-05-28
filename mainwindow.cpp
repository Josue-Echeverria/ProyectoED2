#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, double *cost_abb ,double *cost_avl ,double *cost_arj ,double *cost_heap ,
                       int *t_cres_abb ,int *t_cres_avl ,int *t_cres_arj ,int *t_cres_heap ,
                       int *cos_abb ,int *cos_avl ,int *cos_arj ,int *cos_heap ,
                       int *tcos_abb ,int *tcos_avl ,int *tcos_arj ,int *tcos_heap ,
                       double *prec_fru_abb ,double *prec_fru_avl ,double *prec_fru_arj ,double *prec_fru_heap,
                       double *costo_espantapajaros, int *t_mercado_abrir, int *t_mercado_abierto,
                       int *mercado_rango1,int *mercado_rango2)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->t_mercado_abierto = t_mercado_abierto;
    this->t_mercado_abrir = t_mercado_abrir;

    this->mercado_rango1 = mercado_rango1;
    this->mercado_rango2 = mercado_rango2;

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
    QString h= findChild<QLineEdit*>("lineEdit_precio_espantapajaros")->text();
    QString i= findChild<QLineEdit*>("lineEdit_t_abierto")->text();
    QString j= findChild<QLineEdit*>("lineEdit_t_en_abrir")->text();
    QString k= findChild<QLineEdit*>("lineEdit_price_3")->text();
    QString l= findChild<QLineEdit*>("lineEdit_price_4")->text();

    int plaga_index = findChild<QComboBox*>("comboBox_plagas")->currentIndex();
    QString a1 = findChild<QLineEdit*>("lineEdit_prob")->text();
    QString a2 = findChild<QLineEdit*>("lineEdit_prob_x_t")->text();
    QString a3 = findChild<QLineEdit*>("lineEdit_come")->text();
    QString a4 = findChild<QLineEdit*>("lineEdit_t_come")->text();

    this->nombre = findChild<QLineEdit*>("nombreEdit")->text().toStdString();
    switch(plaga_index){
        case 0:
            this->probCuervo = a1.toInt();
            this->tiempoSegCuervo = a2.toInt();
            this->frutosComenCuervo = a3.toInt();
            this->tiempoSegComenCuervo = a4.toInt();
            break;
        case 1:
            this->probOveja = a1.toInt();
            this->tiempoSegOveja = a2.toInt();
            this->frutosComenOveja = a3.toInt();
            this->tiempoSegComenOveja = a4.toInt();
            break;
        case 2:
            this->probPlaga = a1.toInt();
            this->tiempoSegPlaga = a2.toInt();
            this->frutosComenPlaga = a3.toInt();
            this->tiempoSegComenPlaga = a4.toInt();
            break;
    }
    double randomprice = QRandomGenerator::global()->bounded(d.toInt(), f.toInt()); // Generate random number between 50 and 100

    *this->t_mercado_abierto = i.toInt();
    *this->t_mercado_abrir = j.toInt();

    *this->mercado_rango1 = k.toInt();
    *this->mercado_rango2 = l.toInt();

    *this->costo_espantapajaros = h.toDouble();
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

