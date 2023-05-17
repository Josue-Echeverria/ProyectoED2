#include "ARJ_thread.h"


void ARJ_thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->arj->t_crecer;

    while(true){
        //Este for es el tiempo que dura para crecer y empezar a producir
        while(t_para_crecer > 0){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             *
             */
            std::cout<<"\nARBOL ARJ creciendo "<<t_para_crecer<<std::endl;
            t_para_crecer--;
            QThread::sleep(1);
        }

        for(int i = *this->arj->t_produ_frut; i >= 0; i--){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             */
            std::cout<<"\nARBOL arj produciendo "<<i<<std::endl;

            QThread::sleep(1);

        }

        this->mutex_arj.lock();
        for(int i = *this->arj->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->arj->insert(random);
        }
        this->arj->inorder();
        this->mutex_arj.unlock();
        std::cout<<"\nARBOL Rojinegro "<<std::endl;
       // QThread::sleep(1);
    }

}
