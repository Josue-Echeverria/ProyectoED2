#include "Heap.h"

Heap::Heap(int lar,int *a, int *b, int *c, double *d, double *e){
    this->datos = new double[lar+1];
    for(int i = 0; i < lar+1; i++){
        this->datos[i] = -1;
    }
    this->n_elementos = 0;
    this->largo = lar;
    this->t_crecer = a;
    this->t_produ_frut = b;
    this->n_produ_frut = c;
    this->costo = d;
    this->precio_fruto = e;
}
void Heap::comer(int n){
    while(n > 0 & n_elementos > 0){
        if(this->delete_random() != -1){
            std::cout<<"\nLo elimine"<<std::endl;
            n--;
            this->perdidos++;
        }else
            break;
    }
}

double Heap::vender(int n){
    double acumulador = 0;
    if(n == -1){
        acumulador = this->n_elementos**this->precio_fruto;
        this->vendidos += this->n_elementos;
        eliminar_todo();
        return acumulador;
    }
    while(n > 0 & n_elementos > 0){
        if(this->delete_random() != -1){
            std::cout<<"\nLo elimine"<<std::endl;
            acumulador += *this->precio_fruto;
            n--;
            this->vendidos++;
        }else
            break;
    }
    return acumulador;
}

void Heap::insertar(double n){
    if(largo == n_elementos){
        std::cout<<"Arbol heap lleno"<<std::endl;
    }else{
        shiftright();
        datos[0] = n;
        getmax(0);
        this->n_elementos++;
    }
}

void Heap::eliminar_todo(){
    for(int i = 0; i<n_elementos;i++){
        this->datos[i] = -1;
    }
    this->n_elementos = 0;
}

void Heap::shiftright(){
    for(int i = n_elementos; i>=0; i--){
        datos[i+1] = datos[i];
    }
}

int Heap::getmax(int index){
    if(datos[index]<datos[index*2+1]){
        double temp = datos[index];
        datos[index] = datos[index*2+1];
        datos[index*2+1] = temp;
        return getmax(index*2+1);
    } else if(datos[index]<datos[index*2+2]){
        double temp = datos[index];
        datos[index] = datos[index*2+2];
        datos[index*2+2] = temp;
        return getmax(index*2+2);
    }
    return 0;

}

void Heap::shiftleft_from(int index){
    for(int i = index; i<=n_elementos; i++){
        datos[i] = datos[i+1];
    }
}

double Heap::eliminar(double entrada){
    for(int i = 0; i<n_elementos;i++){
        if(entrada == this->datos[i]){
            int temp = this->datos[i];
            shiftleft_from(i);
            n_elementos--;
            return temp;
        };
    }
    return -1;
};

int Heap::delete_random(){
    if(this->n_elementos == 0)
        return -1;
    else{
        int random = QRandomGenerator::global()->bounded(this->n_elementos);
        double toretrun = this->datos[random];
        shiftleft_from(random);
        this->n_elementos--;
        return toretrun;
    }

}

double Heap::buscar(double entrada){
    for(int i = 0; i<n_elementos;i++){
        if(entrada == this->datos[i]){
            return this->datos[i];
        };
    }
    return -1;
};

void Heap::mostrar(){
    for(int i = 0; i<n_elementos;i++){
        cout<<this->datos[i]<<" ";
    }
}
