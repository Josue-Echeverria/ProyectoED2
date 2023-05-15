#include "Heap_Thread.h"

void Heap_Thread::run(){

    this->running = true;
    QRandomGenerator randomGenerator;

    while(true){
        double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
        std::cout<<"\nARBOL ";
        this->heap->insertar(random);
        this->heap->mostrar();
        QThread::sleep(2);
    }




}
