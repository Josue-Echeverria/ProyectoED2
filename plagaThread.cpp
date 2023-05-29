#include "plagaThread.h"

void plagaThread::run(){
    this->running = true;
    while(true){
        while(plagaLabel->isVisible()){
            if(this->tipo == 3){
                int n = 0;
                while(plagaLabel->isVisible() && (n < *this->tiempoSegComen)){
                    QThread::sleep(1);
                    n++;

                }if(n == *this->tiempoSegComen){
                    fue_comido();
                } else {
                    comer(n,static_cast<float>(n)/static_cast<float>(*this->tiempoSegComen));
                }
            } else
            comer(*this->frutosComen,-1);
            QThread::sleep(1);
        }
        QThread::sleep(*tiempoSeg/cant);
        aparecerPlaga();
        QThread::sleep(1);
    }
}

bool plagaThread::pregunteProbabilidad(){
    int random = QRandomGenerator::global()->generateDouble() * 99 + 1;
    if(random<=*probabilidad){
        return true;
    }
    return false;

}
void plagaThread::comer(int n,float p){
    switch (tab->Tablero[x][y]->arbol) {// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
    case 0:
        break;
    case 1:
        if(p != -1){
            n = p * *this->tab->Tablero[x][y]->Abb->abb->n_elementos;

        }
        this->tab->Tablero[x][y]->Abb->being_eaten = true;
        this->tab->Tablero[x][y]->Abb->n_being_eaten = n;
        break;
    case 2:
        if(p != -1){
            n = p * *this->tab->Tablero[x][y]->Arj->arj->n_elementos;
        }
        this->tab->Tablero[x][y]->Arj->being_eaten = true;
        this->tab->Tablero[x][y]->Arj->n_being_eaten = n;
        break;
    case 3:
        if(p != -1){
            n = p * *this->tab->Tablero[x][y]->Avl->abb->n_elementos;
        }
        this->tab->Tablero[x][y]->Avl->being_eaten = true;
        this->tab->Tablero[x][y]->Avl->n_being_eaten = n;
        break;
    case 4:
        if(p != -1){
            n = p * *this->tab->Tablero[x][y]->Heap->heap->n_elementos;
        }
        this->tab->Tablero[x][y]->Heap->being_eaten = true;
        this->tab->Tablero[x][y]->Heap->n_being_eaten = n;
        break;

    }
}

void plagaThread::fue_comido(){
    switch (tab->Tablero[x][y]->arbol) {// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
    case 0:
        break;
    case 1:
        this->tab->Tablero[x][y]->Abb->got_eaten = true;

        break;
    case 2:
        this->tab->Tablero[x][y]->Arj->got_eaten = true;
        break;
    case 3:
        this->tab->Tablero[x][y]->Avl->got_eaten = true;
        break;
    case 4:
        this->tab->Tablero[x][y]->Heap->got_eaten = true;
        break;

    }
}


void plagaThread::aparecerPlaga(){
    if(pregunteProbabilidad()){
        int randomx = 0;
        int randomy = 0;
        casilla * enUso = NULL;
        while(true){
            randomx = QRandomGenerator::global()->bounded(7);
            randomy = QRandomGenerator::global()->bounded(7);
            enUso = tab->Tablero[randomx][randomy];
            if(enUso->plaga == 0 && enUso->espantaPaj == false){
                //QMutexLocker Locker(mutexTab);
                enUso->plaga = tipo;
                plagaLabel->setVisible(true);
                plagaLabel->setGeometry(enUso->x, enUso->y, 50, 50);
                //mutexTab->unlock();
                break;
            }
        }
        sleep(2);
        if(enUso->arbol == 0 && tipo == 2){
            if(randomx == 0 && randomy == 0){
                if(tab->Tablero[randomx+1][randomy]->arbol != 0 && tab->Tablero[randomx+1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x + 125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy+1]->arbol != 0 && tab->Tablero[randomx][randomy +1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y + 77, 50, 50);
                }
            }else if(randomx == 7 && randomy == 7){
                if(tab->Tablero[randomx-1][randomy]->arbol != 0 && tab->Tablero[randomx -1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x - 125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy-1]->arbol != 0 && tab->Tablero[randomx][randomy -1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y +77, 50, 50);
                }
            }else if(randomx == 7 && randomy == 0){
                if(tab->Tablero[randomx-1][randomy]->arbol != 0 && tab->Tablero[randomx -1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x -125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy+1]->arbol != 0 && tab->Tablero[randomx][randomy +1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y +77, 50, 50);
                }
            }else if(randomx == 0 && randomy == 7){
                if(tab->Tablero[randomx+1][randomy]->arbol != 0  && tab->Tablero[randomx+1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x +125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy-1]->arbol != 0 && tab->Tablero[randomx][randomy -1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y -77, 50, 50);
                }
            }
            else if(randomx == 0){
                if(tab->Tablero[randomx+1][randomy]->arbol != 0  && tab->Tablero[randomx+1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x +125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy+1]->arbol != 0 && tab->Tablero[randomx][randomy +1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y +77, 50, 50);
                }else if(tab->Tablero[randomx][randomy-1]->arbol != 0 && tab->Tablero[randomx][randomy -1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y-77, 50, 50);
                }
            }
            else if(randomx == 7){
                if(tab->Tablero[randomx-1][randomy]->arbol != 0 && tab->Tablero[randomx -1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x -125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy+1]->arbol != 0 && tab->Tablero[randomx][randomy +1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y +77, 50, 50);
                }else if(tab->Tablero[randomx][randomy-1]->arbol != 0 && tab->Tablero[randomx][randomy -1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y-77, 50, 50);
                }
            }
            else if(randomy == 0){
                if(tab->Tablero[randomx-1][randomy]->arbol != 0 && tab->Tablero[randomx -1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x -125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy+1]->arbol != 0 && tab->Tablero[randomx][randomy +1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y +77, 50, 50);
                }else if(tab->Tablero[randomx+1][randomy]->arbol != 0  && tab->Tablero[randomx+1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x+125, enUso->y, 50, 50);
                }
            }
            else if(randomy == 7){
                if(tab->Tablero[randomx-1][randomy]->arbol != 0 && tab->Tablero[randomx -1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x -125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy-1]->arbol != 0 && tab->Tablero[randomx][randomy -1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y -77, 50, 50);
                }else if(tab->Tablero[randomx+1][randomy]->arbol != 0  && tab->Tablero[randomx+1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x+125, enUso->y, 50, 50);
                }
            }else{
                if(tab->Tablero[randomx-1][randomy]->arbol != 0  && tab->Tablero[randomx -1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x -125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy-1]->arbol != 0 && tab->Tablero[randomx][randomy -1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y -77, 50, 50);
                }else if(tab->Tablero[randomx+1][randomy]->arbol != 0  && tab->Tablero[randomx+1][randomy]->plaga == false){
                    plagaLabel->setGeometry(enUso->x+125, enUso->y, 50, 50);
                }else if(tab->Tablero[randomx][randomy+1]->arbol != 0 && tab->Tablero[randomx][randomy +1]->plaga == false){
                    plagaLabel->setGeometry(enUso->x, enUso->y +77, 50, 50);
                }
            }
        }
        this->x = randomy;
        this->y = randomx;
    }
}

void plagaThread::esconderPlaga(){
    plagaLabel->setVisible(false);
}
