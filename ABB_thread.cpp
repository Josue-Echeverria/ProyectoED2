#include "ABB_thread.h"

void ABB_Thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->abb->t_crecer;
    while(true){
        while(t_para_crecer > 0){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             *
             */
            t_para_crecer--;
            std::cout<<"\nARBOL ABB creciendo "<<t_para_crecer<<std::endl;

            QThread::sleep(1);
        }
        for(int i = *this->abb->t_produ_frut; i >= 0; i--){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             */
            std::cout<<"\nARBOL ABB produciendo "<<i<<std::endl;

            QThread::sleep(1);

        }
        //Aqui produce fruta xd
        this->mutex_abb.lock();
        for(int i = *this->abb->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->abb->meterABB(random);
        }
        this->abb->inorder(this->abb->raiz);
        this->mutex_abb.unlock();

        std::cout<<"\nARBOL ABB "<<std::endl;
      //  QThread::sleep(1);
    }

}
