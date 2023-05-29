#ifndef ARJ_THREAD_H
#define ARJ_THREAD_H
#include "ARJ.h"
#include <mutex>
#include "qlabel.h"
#include "QTableWidget"
#include "QTableWidgetItem"
class ARJ_thread : public QThread{
public:
    ARJ_thread(int *a, int *b, int *c, double *d, double *e,QTableWidget *f,int g,int h,double *i,int *j,int *k,int *l,QLabel *m){
        this->arj = new RBTree(a, b, c, d, e, j, k, l);
        this->imagen_interfaz = m;
        this->x = g;
        this->y = h;
        this->plata = i;

        this->tabla_intefaz = f;
    };
    int x,y;
    double *plata;

    void run();
    QTableWidget *tabla_intefaz;
    int pos_table;
    bool has_2_sell = false;
    bool has_2_sell_all = false;
    bool being_eaten = false;
//private:m
    std::mutex mutex_arj;
    void actualizar_interfaz();
    QLabel *imagen_interfaz;
    void actualizar_interfaz_aux(int,QString);
    int n_being_eaten = 0;
    bool got_eaten = false;
    void produce_n(int);
    RBTree *arj;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}

};

#endif // ARJ_THREAD_H
