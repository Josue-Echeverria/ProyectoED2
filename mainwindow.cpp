#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "gamewindow.h"

MainWindow::MainWindow(QWidget *parent, int cost_abb ,int cost_avl ,int cost_arj ,int cost_heap ,
                       int t_cres_abb ,int t_cres_avl ,int t_cres_arj ,int t_cres_heap ,
                       int cos_abb ,int cos_avl ,int cos_arj ,int cos_heap ,
                       int tcos_abb ,int tcos_avl ,int tcos_arj ,int tcos_heap ,
                       double prec_fru_abb ,double prec_fru_avl ,double prec_fru_arj ,double prec_fru_heap )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    this->cosecha_abb = cos_abb;
    this->cosecha_cada_t_abb = tcos_abb;
    this->precio_frut_abb = prec_fru_abb;
    this->costo_abb = cos_abb;
    this->t_crecimien_abb = t_cres_abb;

    this->cosecha_avl = cos_avl;
    this->cosecha_cada_t_avl = tcos_avl;
    this->precio_frut_avl = prec_fru_avl;
    this->costo_avl = cos_avl;
    this->t_crecimien_avl = t_cres_avl;

    this->cosecha_arj = cos_arj;
    this->cosecha_cada_t_arj = tcos_arj;
    this->precio_frut_arj = prec_fru_arj;
    this->costo_arj = cos_arj;
    this->t_crecimien_arj = t_cres_arj;

    this->cosecha_heap = cos_heap;
    this->cosecha_cada_t_heap = tcos_heap;
    this->precio_frut_heap = prec_fru_heap;
    this->costo_heap = cos_heap;
    this->t_crecimien_heap = t_cres_heap;

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

