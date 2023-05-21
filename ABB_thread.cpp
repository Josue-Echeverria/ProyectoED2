#include "ABB_thread.h"

void ABB_Thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"ABB");
    //    actualizar_interfaz_aux(1,);
    actualizar_interfaz_aux(2,QString::number(this->abb->n_elementos));
    actualizar_interfaz_aux(3,QString::number(this->abb->n_elementos * *this->abb->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(this->abb->perdidos));
    actualizar_interfaz_aux(5,QString::number(this->abb->vendidos));

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



void ABB_Thread::run(){
    this->running = true;
    QRandomGenerator randomGenerator;
    int t_para_crecer = *this->abb->t_crecer;
    int temp = 2;
    sleep(2);

    this->pos_table = this->tabla_intefaz->columnCount();
    std::cout<<"AAAAAAAAAAAAAAAA"<<pos_table<<std::endl;

    this->tabla_intefaz->insertColumn(pos_table);
    while(true){
        this->actualizar_interfaz();

        /* ESTO ES LA PRUBA PARA LAS PLAGAS

        if(temp == 0){
            std::cout<<"\nVoy a eliminar"<<t_para_crecer<<std::endl;
            this->abb->inorder(this->abb->raiz);
            if(this->abb->del_min() != -1){
                std::cout<<"\nLo elimine"<<t_para_crecer<<std::endl;
            }
            this->abb->inorder(this->abb->raiz);
            temp = 2;
        }else{
            temp--;
            std::cout<<"\nEliminand en:"<<temp<<std::endl;
        }*/
        while(t_para_crecer > 0){
            t_para_crecer--;
            std::cout<<"\nARBOL ABB creciendo "<<t_para_crecer<<std::endl;
            QThread::sleep(1);
        }
        for(int i = *this->abb->t_produ_frut; i >= 0; i--){

            if(this->being_eaten){
                this->abb->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                this->abb->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                this->abb->vender(1);
                this->has_2_sell = false;
            }
            std::cout<<"\nARBOL ABB produciendo "<<i<<std::endl;

            QThread::sleep(1);
            this->actualizar_interfaz();

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
