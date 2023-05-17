#include "avl_thread.h"

void AVL_Thread::run(){

    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->avl->t_crecer;

    while(true){

        while(t_para_crecer > 0){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             *
             */
            t_para_crecer--;
            std::cout<<"\nARBOL AVL creciendo "<<t_para_crecer<<std::endl;

            QThread::sleep(1);
        }
        for(int i = *this->avl->t_produ_frut; i >= 0; i--){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             */
            std::cout<<"\nARBOL AVL produciendo "<<i<<std::endl;

            QThread::sleep(1);

        }
        this->mutex_avl.lock();
        for(int i = *this->avl->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->avl->Insertar(random);
        }
        std::cout<<"\nARBOL avl"<<std::endl;
        this->avl->InOrden(Mostrar);
        this->mutex_avl.unlock();

//        QThread::sleep(2);
    }




}
