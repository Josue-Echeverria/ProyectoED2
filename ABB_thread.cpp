#include "ABB_thread.h"

void ABB_Thread::actualizar_interfaz(){
    if(this->a)
    actualizar_interfaz_aux(0,"ABB");
    else
    actualizar_interfaz_aux(0,"AVL");
    actualizar_interfaz_aux(1,"("+QString::number(this->x)+","+QString::number(this->y)+")");
    actualizar_interfaz_aux(2,QString::number(*this->abb->n_elementos));
    actualizar_interfaz_aux(3,QString::number(*this->abb->n_elementos * *this->abb->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(*this->abb->perdidos));
    actualizar_interfaz_aux(5,QString::number(*this->abb->vendidos));

}

void ABB_Thread::actualizar_interfaz_aux(int row,QString text){
    QTableWidgetItem* item = tabla_intefaz->item(row, this->pos_table);
    if (!item)
    {
        item = new QTableWidgetItem();
        tabla_intefaz->setItem(row, this->pos_table, item);
    }
    item->setText(text);
}


void ABB_Thread::produce_n(int n){
    for(int i = n; i > 0;i--){
        double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
        this->abb->meterABB(random);
    }
}

void ABB_Thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->abb->t_crecer;
    this->pos_table = this->tabla_intefaz->columnCount();
    this->tabla_intefaz->insertColumn(pos_table);
    while(true){
        this->actualizar_interfaz();
        while(t_para_crecer > 0){
            t_para_crecer--;
            QThread::sleep(1);
        }
        for(int i = *this->abb->t_produ_frut; i > 0; i--){
            if(got_eaten){
                break;
            }
            this->actualizar_interfaz();
            if(this->being_eaten){
                this->abb->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                *this->plata += this->abb->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                *this->plata += this->abb->vender(1);
                this->has_2_sell = false;
            }
            QThread::sleep(1);
        }
        this->mutex_abb.lock();
        for(int i = *this->abb->n_produ_frut; i > 0; i--){
            if (!this->got_eaten){
                double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
                this->abb->meterABB(random);
            }
        }
        if(this->got_eaten){
            this->abb->comer(*this->abb->n_elementos);
            this->imagen_interfaz->setPixmap(QPixmap());
            break;
        }
        this->mutex_abb.unlock();
    }

}
