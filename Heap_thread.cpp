#include "Heap_Thread.h"

void Heap_Thread::run(){

    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->heap->t_crecer;

    while(true){
        while(t_para_crecer > 0){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             *
             */
            t_para_crecer--;
            std::cout<<"\nARBOL heap creciendo "<<t_para_crecer<<std::endl;
            QThread::sleep(1);
        }
        for(int i = *this->heap->t_produ_frut; i >= 0; i--){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             */
            std::cout<<"\nARBOL heap produciendo "<<i<<std::endl;
            QThread::sleep(1);

        }
        this->mutex_heap.lock();
        for(int i = *this->heap->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->heap->insertar(random);
        }
        this->heap->mostrar();
        std::cout<<"\nARBOL heap"<<std::endl;
        this->mutex_heap.unlock();
        // QThread::sleep(2);
    }
}
