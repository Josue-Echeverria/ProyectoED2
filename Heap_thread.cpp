#include "Heap_Thread.h"

void Heap_Thread::actualizar_interfaz(){
    actualizar_interfaz_aux(0,"Heap");
    actualizar_interfaz_aux(1,"("+QString::number(this->x)+","+QString::number(this->y)+")");
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
    int t_para_crecer = *this->heap->t_crecer;
    this->pos_table = this->tabla_intefaz->columnCount();
    this->tabla_intefaz->insertColumn(pos_table);
    while(true){
        this->actualizar_interfaz();
        while(t_para_crecer > 0){
            t_para_crecer--;
            QThread::sleep(1);
        }
        for(int i = *this->heap->t_produ_frut; i > 0; i--){
            this->actualizar_interfaz();
            if(this->being_eaten){
                this->heap->comer(n_being_eaten);
                this->being_eaten = false;
            }
            if(this->has_2_sell_all){
                *this->plata += this->heap->vender(-1);
                this->has_2_sell_all = false;
            }
            if (this->has_2_sell){
                *this->plata += this->heap->vender(1);
                this->has_2_sell = false;
            }
            QThread::sleep(1);
        }
        this->mutex_heap.lock();
        for(int i = *this->heap->n_produ_frut; i > 0; i--){
            double random = QRandomGenerator::global()->generateDouble() * 4 + 1;
            this->heap->insertar(random);
        }
        this->heap->mostrar();
      //  std::cout<<"\nARBOL heap"<<std::endl;
        this->mutex_heap.unlock();
    }
}
