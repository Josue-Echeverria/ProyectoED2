#include "ARJ_thread.h"


void ARJ_thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"Roji-Negro");
    actualizar_interfaz_aux(1,"("+QString::number(this->x)+","+QString::number(this->y)+")");
    actualizar_interfaz_aux(2,QString::number(*this->arj->n_elementos));
    actualizar_interfaz_aux(3,QString::number(*this->arj->n_elementos * *this->arj->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(*this->arj->perdidos));
    actualizar_interfaz_aux(5,QString::number(*this->arj->vendidos));

}

void ARJ_thread::actualizar_interfaz_aux(int row,QString text){
    QTableWidgetItem* item = tabla_intefaz->item(row, this->pos_table);
    if (!item)
    {
        item = new QTableWidgetItem();
        tabla_intefaz->setItem(row, this->pos_table, item);
    }
    item->setText(text);
}

void ARJ_thread::produce_n(int n){
    for(int i = n; i > 0;i--){
        double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
        this->arj->insertValue(random);
    }
}

void ARJ_thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->arj->t_crecer;

    this->pos_table = this->tabla_intefaz->columnCount();
    this->tabla_intefaz->insertColumn(pos_table);
    while(true){
        this->actualizar_interfaz();
        while(t_para_crecer > 0){
            t_para_crecer--;
            QThread::sleep(1);
        }
        for(int i = *this->arj->t_produ_frut; i > 0; i--){
            if(got_eaten){
                break;
            }
            this->actualizar_interfaz();
            if(this->being_eaten){
                this->arj->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                *this->plata += this->arj->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                *this->plata += this->arj->vender(1);
                this->has_2_sell = false;
            }
            QThread::sleep(1);
        }
        this->mutex_arj.lock();
        for(int i = *this->arj->n_produ_frut; i > 0; i--){
            if (!this->got_eaten){
                double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
                this->arj->insertValue(random);
            }
        }
        this->mutex_arj.unlock();
        if(this->got_eaten){
            this->arj->comer(*this->arj->n_elementos);
            this->imagen_interfaz->setPixmap(QPixmap());
            break;
        }
    }

}
