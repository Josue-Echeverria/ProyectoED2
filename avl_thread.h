#ifndef AVL_THREAD_H
#define AVL_THREAD_H
#include <mutex>

#include "AVL.h"
#include "QTableWidget"

class AVL_Thread: public QThread{
public:
    AVL_Thread(int *a, int *b, int *c, int *d, double *e, QTableWidget *f){
        this->avl = new AVL(a, b, c, d, e);
        this->tabla_intefaz = f;
    };
    QTableWidget *tabla_intefaz;
    int pos_table;
    void actualizar_interfaz();
    void actualizar_interfaz_aux(int,QString);
    bool has_2_sell = false;
    bool has_2_sell_all = false;
    bool being_eaten = false;
    int n_being_eaten = 0;

    void run();
    std::mutex mutex_avl;

    AVL *avl;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}
};

#endif // AVL_THREAD_H
