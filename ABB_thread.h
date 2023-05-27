#ifndef ABB_THREAD_H
#define ABB_THREAD_H
#include <mutex>
#include "ABB.h"
#include "QTableWidget"

class ABB_Thread : public QThread{
public:
    ABB_Thread(int *a, int *b, int *c, double *d, double *e, QTableWidget *f,int g,int h, double *i,bool aa){
        this->abb = new ABB(a, b, c, d, e);
        this->x = g;
        this->a = aa;
        this->y = h;
        this->tabla_intefaz = f;
        this->plata = i;
    };
    int x,y;
    double *plata;
    bool a;
    void run();
    QTableWidget *tabla_intefaz;
    int pos_table;
    void actualizar_interfaz();
    void actualizar_interfaz_aux(int,QString);
    bool has_2_sell = false;
    bool has_2_sell_all = false;
    bool being_eaten = false;
    bool got_eaten = false;
    int n_being_eaten = 0;
//private:
    std::mutex mutex_abb;

    ABB *abb;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}

};

#endif // ABB_THREAD_H
