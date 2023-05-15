#include "ARJ_thread.h"


void ARJ_thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;

    while(true){
        double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
        std::cout<<"\nARBOL Rojinegro ";
        this->arj->insert(random);
        this->arj->inorder();
        QThread::sleep(2);
    }

}
