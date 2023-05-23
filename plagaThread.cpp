#include "plagaThread.h"
void plagaThread::run(){
    this->running = true;
    while(true){
        while(plagaLabel->isVisible()){
            QThread::sleep(1);
            //verificarGranjero();
        }
        QThread::sleep(tiempoSeg);
        for(int i = 0; i < cant; i++){
            aparecerPlaga();
            QThread::sleep(1);
        }
    }
}
bool plagaThread::pregunteProbabilidad(){
    int random = QRandomGenerator::global()->generateDouble() * 99 + 1;

    if(random<=probabilidad){
        return true;
    }
    return false;
}

void plagaThread::aparecerPlaga(){
    if(pregunteProbabilidad()){
        int randomx = 0;
        int randomy = 0;
        while(true){
            randomx = QRandomGenerator::global()->generateDouble() * 7 + 1;
            randomy =  QRandomGenerator::global()->generateDouble() * 7 + 1;
            casilla * enUso = tab->Tablero[randomx][randomy];
            if(enUso->plaga == 0 && enUso->espantaPaj == false && enUso->granjero ==false){
                //QMutexLocker Locker(mutexTab);
                enUso->plaga = tipo;
                plagaLabel->setVisible(true);
                plagaLabel->setGeometry(enUso->x, enUso->y, 50, 50);
                //mutexTab->unlock();
                break;
            }
        }
    }
}

void plagaThread::esconderPlaga(){
    plagaLabel->setVisible(false);
}
