#ifndef AVL_THREAD_H
#define AVL_THREAD_H
#include <mutex>

#include "AVL.h"


class AVL_Thread: public QThread{
public:
    AVL_Thread(){
        this->avl = new AVL();
    };

    void run();
    std::mutex mutex_avl;

    AVL *avl;
    bool running;
    void pausar(){running = false;}
    void reanudar(){running = true;}
};

#endif // AVL_THREAD_H
