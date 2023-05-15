#include "avl_thread.h"

void AVL_Thread::run(){

    this->running = true;
    QRandomGenerator randomGenerator;

    while(true){
        double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
        std::cout<<"\nARBOL avl";
        this->avl->Insertar(random);
        this->avl->InOrden(Mostrar);
        QThread::sleep(2);
    }




}
