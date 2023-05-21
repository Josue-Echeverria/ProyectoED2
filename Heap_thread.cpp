#include "Heap_Thread.h"

void Heap_Thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"Heap");
    //    actualizar_interfaz_aux(1,);
    actualizar_interfaz_aux(2,QString::number(this->heap->n_elementos));
    actualizar_interfaz_aux(3,QString::number(this->heap->n_elementos * *this->heap->precio_fruto));
    actualizar_interfaz_aux(4,QString::number(this->heap->perdidos));
    actualizar_interfaz_aux(5,QString::number(this->heap->vendidos));

}

void Heap_Thread::actualizar_interfaz_aux(int row,QString text){
    QTableWidgetItem* item = tabla_intefaz->item(row, this->pos_table);
    if (!item)
    {
        item = new QTableWidgetItem();
        tabla_intefaz->setItem(row, this->pos_table, item);
    }
    item->setText(text);
}
void Heap_Thread::run(){

    this->running = true;
    QRandomGenerator randomGenerator;
    sleep(3);

    int t_para_crecer = *this->heap->t_crecer;
    this->pos_table = this->tabla_intefaz->columnCount();
    std::cout<<"AAAAAAAAAAAAAAAA"<<pos_table<<std::endl;
    this->tabla_intefaz->insertColumn(pos_table);
    int temp = 2;

    while(true){
        this->actualizar_interfaz();

        /* ESTO ES LA PRUBA PARA LAS PLAGAS
        if(temp == 0 ){
            std::cout<<"\nVoy a eliminar"<<t_para_crecer<<std::endl;
            this->heap->mostrar();

            if(this->heap->delete_random() != -1){
                std::cout<<"\nLo elimine"<<t_para_crecer<<std::endl;
            }
            this->heap->mostrar();

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
            std::cout<<"\nARBOL heap creciendo "<<t_para_crecer<<std::endl;
            QThread::sleep(1);
        }
        for(int i = *this->heap->t_produ_frut; i >= 0; i--){
            if(this->being_eaten){
                this->heap->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                this->heap->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                this->heap->vender(1);
                this->has_2_sell = false;
            }
            std::cout<<"\nARBOL heap produciendo "<<i<<std::endl;
            QThread::sleep(1);

        }
        this->mutex_heap.lock();
        for(int i = *this->heap->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->heap->insertar(random);
        }
        this->heap->mostrar();
        std::cout<<"\nARBOL heap"<<std::endl;
        this->mutex_heap.unlock();
        // QThread::sleep(2);
    }
}
