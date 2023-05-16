#include "ABB_thread.h"

void ABB_Thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->abb->t_crecer;
    while(true){
        for(int i =*this->abb->t_crecer; i > 0; i--){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             */
            t_para_crecer--;
            QThread::sleep(1);
        }
        for(int i = *this->abb->t_produ_frut; i > 0; i--){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             */
            QThread::sleep(1);

        }
        this->mutex_abb.lock();
        for(int i = *this->abb->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->abb->meterABB(random);
        }
        this->mutex_abb.lock();
        this->abb->inorder(this->abb->raiz);
        std::cout<<"\nARBOL ABB ";
        QThread::sleep(1);
    }

}
