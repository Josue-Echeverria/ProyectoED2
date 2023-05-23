#ifndef MERCADO_H
#define MERCADO_H

#include <QDialog>
#include <QLabel>
#include "granjero.h"
namespace Ui {
class Mercado;
}

class Mercado : public QDialog
{
    Q_OBJECT

public:

    int costo_abb;
    int costo_heap;
    int costo_arj;
    int costo_avl;
    int costo_espantapajaros;
    QLabel *labelplata;
    granjero *granjero;
    explicit Mercado(QWidget *parent = nullptr,int  cost_abb = -1,int  cost_avl = -1,int  cost_arj = -1,int  cost_heap = -1,
                                             int  t_cres_abb = -1,int  t_cres_avl = -1,int  t_cres_arj = -1,int  t_cres_heap = -1,
                                             int  cos_abb= -1,int  cos_avl = -1,int  cos_arj =-1,int  cos_heap = -1,
                                             int  tcos_abb = -1,int  tcos_avl =-1,int  tcos_arj = -1,int  tcos_heap = -1,
                                             double  prec_fru_abb = -1,double  prec_fru_avl =-1,double  prec_fru_arj = -1,double  prec_fru_heap = -1,
                                             class granjero *granjero = NULL,int cost_espantapajaros = -1);
    ~Mercado();

private slots:
    void on_pushButton_comprar_ABB_clicked();

    void on_pushButton_comprar_AVL_clicked();

    void on_pushButton_comprar_ARJ_clicked();

    void on_pushButton_comprar_Heap_clicked();

    void on_pushButton_comprar_espantapajaros_clicked();

private:
    Ui::Mercado *ui;
};

#endif // MERCADO_H
