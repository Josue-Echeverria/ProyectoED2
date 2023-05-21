#ifndef HEAP_THREAD_H
#define HEAP_THREAD_H
#include "Heap.h"
#include <mutex>
#include "QTableWidget"
class Heap_Thread: public QThread{
public:
    Heap_Thread(int largo,int *a, int *b, int *c, int *d, double *e,QTableWidget* f){
        this->heap = new Heap(largo,a, b, c, d, e);
        this->tabla_intefaz = f;
    };

    void run();
    std::mutex mutex_heap;
    QTableWidget *tabla_intefaz;
    int pos_table;
    bool has_2_sell = false;
    bool has_2_sell_all = false;
    bool being_eaten = false;
    int n_being_eaten = 0;

    void actualizar_interfaz();
    void actualizar_interfaz_aux(int,QString);
    Heap *heap;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}
};

#endif // HEAP_THREAD_H
