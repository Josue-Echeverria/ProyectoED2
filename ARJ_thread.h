#ifndef ARJ_THREAD_H
#define ARJ_THREAD_H
#include "ARJ.h"
#include <mutex>
#include "QTableWidget"
#include "QTableWidgetItem"
class ARJ_thread : public QThread{
public:
    ARJ_thread(int *a, int *b, int *c, int *d, double *e,QTableWidget *f,int g,int h){
        this->arj = new RBTree(a, b, c, d, e);
        this->x = g;
        this->y = h;
        this->tabla_intefaz = f;
    };
    int x,y;

    void run();
    QTableWidget *tabla_intefaz;
    int pos_table;
    bool has_2_sell = false;
    bool has_2_sell_all = false;
    bool being_eaten = false;
//private:
    std::mutex mutex_arj;
    void actualizar_interfaz();
    void actualizar_interfaz_aux(int,QString);
    int n_being_eaten = 0;

    RBTree *arj;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}

};

#endif // ARJ_THREAD_H
