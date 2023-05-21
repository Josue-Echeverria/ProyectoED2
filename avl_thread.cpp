#include "avl_thread.h"

void AVL_Thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"AVL");
    //    actualizar_interfaz_aux(1,);
    actualizar_interfaz_aux(2,QString::number(this->avl->n_elementos));
    actualizar_interfaz_aux(3,QString::number(this->avl->n_elementos * *this->avl->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(this->avl->perdidos));
    actualizar_interfaz_aux(5,QString::number(this->avl->vendidos));

}

void AVL_Thread::actualizar_interfaz_aux(int row,QString text){
    QTableWidgetItem* item = tabla_intefaz->item(row, this->pos_table);
    if (!item)
    {
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
    std::cout<<"AAAAAAAAAAAAAAAA"<<pos_table<<std::endl;

    int temp = 2;
    while(true){
        this->actualizar_interfaz();
        /* ESTO ES LA PRUBA PARA LAS PLAGAS

        if(temp == 0 ){
            std::cout<<"\nVoy a eliminar"<<t_para_crecer<<std::endl;
            this->avl->InOrden(Mostrar);

            if(this->avl->del_min() != -1){
                std::cout<<"\nLo elimine"<<t_para_crecer<<std::endl;
            }
            this->avl->InOrden(Mostrar);

            temp = 2;
        }else{
            temp--;
            std::cout<<"\nEliminand en:"<<temp<<std::endl;

        }
*/
        while(t_para_crecer > 0){
            /*
             * Aqui deberia de tipo modificar la inferfaz maybe
             *
             */
            t_para_crecer--;
            std::cout<<"\nARBOL AVL creciendo "<<t_para_crecer<<std::endl;

            QThread::sleep(1);
        }
        for(int i = *this->avl->t_produ_frut; i >= 0; i--){
            if(this->being_eaten){
                this->avl->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                this->avl->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                this->avl->vender(1);
                this->has_2_sell = false;
            }
            std::cout<<"\nARBOL AVL produciendo "<<i<<std::endl;

            QThread::sleep(1);

        }
        this->mutex_avl.lock();
        for(int i = *this->avl->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->avl->Insertar(random);
        }
        std::cout<<"\nARBOL avl"<<std::endl;
        this->avl->InOrden(Mostrar);
        this->mutex_avl.unlock();

//        QThread::sleep(2);
    }




}
