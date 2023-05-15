#include "ABB_thread.h"

void ABB_Thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;

    while(true){

        double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
     //   std::cout<<random<<std::endl;

        insertABB(this->abb,random);
        std::cout<<"\nARBOL ABB ";
        inorder(this->abb);
        QThread::sleep(2);
    }

}
