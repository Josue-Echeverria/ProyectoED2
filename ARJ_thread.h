#ifndef ARJ_THREAD_H
#define ARJ_THREAD_H
#include "ARJ.h"
#include <mutex>


class ARJ_thread : public QThread{
public:
    ARJ_thread(){
        this->arj = new RBTree();
    };

    void run();

//private:
    std::mutex mutex_arj;

    RBTree *arj;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}

};

#endif // ARJ_THREAD_H
