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
    int rango1;
    int rango2;
    bool precios_aumentan;
    int variacion_precios;
    double costo_abb;
    double costo_heap;
    double costo_arj;
    double costo_avl;
    int costo_espantapajaros;
    QLabel *labelplata;
    QLabel *label_variacion_precio;
    granjero *granjero;
    explicit Mercado(QWidget *parent = nullptr,double  cost_abb = -1,double  cost_avl = -1,double  cost_arj = -1,double  cost_heap = -1,
                                             int  t_cres_abb = -1,int  t_cres_avl = -1,int  t_cres_arj = -1,int  t_cres_heap = -1,
                                             int  cos_abb= -1,int  cos_avl = -1,int  cos_arj =-1,int  cos_heap = -1,
                                             int  tcos_abb = -1,int  tcos_avl =-1,int  tcos_arj = -1,int  tcos_heap = -1,
                                             double  prec_fru_abb = -1,double  prec_fru_avl =-1,double  prec_fru_arj = -1,double  prec_fru_heap = -1,
                                             class granjero *granjero = NULL,double cost_espantapajaros = -1, int rango1 = -1, int rango2 = -1) ;
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
class mercado_thread : public QThread{
public:
    int *t_en_abrir;
    int *t_abierto;
    bool abierto = false;
    QLabel *contador_interfaz;
    QLabel *plata_interfaz;
    double *plata;
    void actualizar_interfaz(int n);
    mercado_thread(int *a, int *b, QLabel *c,double *d,QLabel *e){
        this->t_abierto = a;
        this->t_en_abrir = b;
        this->plata_interfaz = e;
        this->plata = d;

        this->contador_interfaz = c;
    }
    void run();
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}

};
#endif // MERCADO_H
