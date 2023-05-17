#ifndef ABB_THREAD_H
#define ABB_THREAD_H
#include <mutex>
#include "ABB.h"

class ABB_Thread : public QThread{
public:
    ABB_Thread(int *a, int *b, int *c, int *d, double *e){
        this->abb = new ABB(a, b, c, d, e);
    };

    void run();

//private:
    std::mutex mutex_abb;

    ABB *abb;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}

};

#endif // ABB_THREAD_H
