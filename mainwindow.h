#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QThread>
#include "QRandomGenerator"
//#include "gamewindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int *costo_abb;
    int *costo_heap;
    int *costo_arj;
    int *costo_avl;

    int *t_crecimien_abb;
    int *t_crecimien_heap;
    int *t_crecimien_avl;
    int *t_crecimien_arj;

    int *cosecha_abb;
    int *cosecha_heap;
    int *cosecha_arj;
    int *cosecha_avl;

    int *cosecha_cada_t_abb;
    int *cosecha_cada_t_avl;
    int *cosecha_cada_t_arj;
    int *cosecha_cada_t_heap;

    double *precio_frut_abb;
    double *precio_frut_arj;
    double *precio_frut_heap;
    double *precio_frut_avl;


public:
    MainWindow(QWidget *parent = nullptr, int *cost_abb = NULL,int *cost_avl = NULL,int *cost_arj = NULL,int *cost_heap = NULL,
               int *t_cres_abb = NULL,int *t_cres_avl = NULL,int *t_cres_arj = NULL,int *t_cres_heap = NULL,
               int *cos_abb= NULL,int *cos_avl = NULL,int *cos_arj =NULL,int *cos_heap = NULL,
               int *tcos_abb = NULL,int *tcos_avl =NULL,int *tcos_arj = NULL,int *tcos_heap = NULL,
               double *prec_fru_abb = NULL,double *prec_fru_avl =NULL,double *prec_fru_arj = NULL,double *prec_fru_heap = NULL);
    ~MainWindow();

private slots:
    void on_pButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_guardar_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
