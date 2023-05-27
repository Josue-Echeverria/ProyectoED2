#ifndef AVL_THREAD_H
#define AVL_THREAD_H
#include <mutex>
#include "AVL.h"
#include "QTableWidget"

class AVL_Thread: public QThread{
public:
    AVL_Thread(int *a, int *b, int *c, double *d, double *e, QTableWidget *f,int g,int h,double *i){
        this->avl = new ABB(a, b, c, d, e);
        this->x = g;
        this->y = h;
        this->tabla_intefaz = f;
        this->plata = i;
    };
    int x,y;
    double *plata;
    QTableWidget *tabla_intefaz;
    int pos_table;
    void actualizar_interfaz();
    void actualizar_interfaz_aux(int,QString);
    bool has_2_sell = false;
    bool has_2_sell_all = false;
    bool being_eaten = false;
    AVL *lvl;
    int n_being_eaten = 0;
    bool got_eaten = false;

    void run();
    std::mutex mutex_avl;

    ABB *avl;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}
};

#endif // AVL_THREAD_H
