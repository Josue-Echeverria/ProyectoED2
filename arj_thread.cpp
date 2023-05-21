#include "ARJ_thread.h"


void ARJ_thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"Roji-Negro");
//    actualizar_interfaz_aux(1,);
    actualizar_interfaz_aux(2,QString::number(this->arj->n_elementos));
    actualizar_interfaz_aux(3,QString::number(this->arj->n_elementos * *this->arj->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(this->arj->perdidos));
    actualizar_interfaz_aux(5,QString::number(this->arj->vendidos));

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

void ARJ_thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->arj->t_crecer;
    int temp = 2;
    sleep(1);
    this->pos_table = this->tabla_intefaz->columnCount();
    std::cout<<"AAAAAAAAAAAAAAAA"<<pos_table<<std::endl;
    this->tabla_intefaz->insertColumn(pos_table);
    while(true){

        this->actualizar_interfaz();
/*
        if(temp == 0){
            std::cout<<"\nVoy a eliminar"<<t_para_crecer<<std::endl;
            this->arj->inorder();

            if(this->arj->del_min() != -1){
                std::cout<<"\nLo elimine"<<t_para_crecer<<std::endl;
            }
            this->arj->inorder();

            temp = 2;
        }else{
            temp--;
            std::cout<<"\nEliminand en:"<<temp<<std::endl;
        }*/
        //Este for es el tiempo que dura para crecer y empezar a producir
        while(t_para_crecer > 0){

            std::cout<<"\nARBOL ARJ creciendo "<<t_para_crecer<<std::endl;
            t_para_crecer--;
            QThread::sleep(1);
        }

        for(int i = *this->arj->t_produ_frut; i >= 0; i--){
            if(this->being_eaten){
                this->arj->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                this->arj->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                this->arj->vender(1);
                this->has_2_sell = false;
            }
            std::cout<<"\nARBOL arj produciendo "<<i<<std::endl;

            QThread::sleep(1);

        }

        this->mutex_arj.lock();
        for(int i = *this->arj->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->arj->insertValue(random);
        }
        this->arj->inorder();
        this->mutex_arj.unlock();
        std::cout<<"\nARBOL Rojinegro "<<std::endl;
       // QThread::sleep(1);
    }

}
