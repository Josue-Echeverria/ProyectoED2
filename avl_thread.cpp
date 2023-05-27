#include "avl_thread.h"

void AVL_Thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"AVL");
    actualizar_interfaz_aux(1,"("+QString::number(this->x)+","+QString::number(this->y)+")");
    actualizar_interfaz_aux(2,QString::number(this->avl->n_elementos));
    actualizar_interfaz_aux(3,QString::number(this->avl->n_elementos * *this->avl->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(this->avl->perdidos));
    actualizar_interfaz_aux(5,QString::number(this->avl->vendidos));

}

void AVL_Thread::actualizar_interfaz_aux(int row,QString text){
    QTableWidgetItem* item = tabla_intefaz->item(row, this->pos_table);
    if (!item){
        item = new QTableWidgetItem();
        tabla_intefaz->setItem(row, this->pos_table, item);
    }
    item->setText(text);
}



void AVL_Thread::run(){

    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->avl->t_crecer;
    this->pos_table = this->tabla_intefaz->columnCount();
    this->tabla_intefaz->insertColumn(pos_table);
    while(true){
        this->actualizar_interfaz();

        while(t_para_crecer > 0){
            t_para_crecer--;
            QThread::sleep(1);
        }
        for(int i = *this->avl->t_produ_frut; i > 0; i--){
            this->actualizar_interfaz();
            if(this->being_eaten){
                this->avl->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                *this->plata += this->avl->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                *this->plata += this->avl->vender(1);
                this->has_2_sell = false;
            }
            std::cout<<"\nProduciendo en: "<<i<<std::endl;

            QThread::sleep(1);

        }
        this->mutex_avl.lock();
        for(int i = *this->avl->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->avl->meterABB(random);
            this->avl->n_elementos++;

        }
        this->mutex_avl.unlock();

//        QThread::sleep(2);
    }




}
