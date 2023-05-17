#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int costo_abb;
    int costo_heap;
    int costo_arj;
    int costo_avl;

    int t_crecimien_abb;
    int t_crecimien_heap;
    int t_crecimien_avl;
    int t_crecimien_arj;

    int cosecha_abb;
    int cosecha_heap;
    int cosecha_arj;
    int cosecha_avl;

    int cosecha_cada_t_abb;
    int cosecha_cada_t_avl;
    int cosecha_cada_t_arj;
    int cosecha_cada_t_heap;

    double precio_frut_abb;
    double precio_frut_arj;
    double precio_frut_heap;
    double precio_frut_avl;


public:
    MainWindow(QWidget *parent = nullptr, int cost_abb = -1,int cost_avl = -1,int cost_arj = -1,int cost_heap = -1,
               int t_cres_abb = -1,int t_cres_avl = -1,int t_cres_arj = -1,int t_cres_heap = -1,
               int cos_abb = -1,int cos_avl = -1,int cos_arj = -1,int cos_heap = -1,
               int tcos_abb = -1,int tcos_avl = -1,int tcos_arj = -1,int tcos_heap = -1,
               double prec_fru_abb = -1,double prec_fru_avl = -1,double prec_fru_arj = -1,double prec_fru_heap = -1);
    ~MainWindow();

private slots:
    void on_pButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
