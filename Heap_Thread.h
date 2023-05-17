#ifndef HEAP_THREAD_H
#define HEAP_THREAD_H
#include "Heap.h"
#include <mutex>

class Heap_Thread: public QThread{
public:
    Heap_Thread(int largo,int *a, int *b, int *c, int *d, double *e){
        this->heap = new Heap(largo,a, b, c, d, e);
    };

    void run();
    std::mutex mutex_heap;

    Heap *heap;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}
};

#endif // HEAP_THREAD_H
