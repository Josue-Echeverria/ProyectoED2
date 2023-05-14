#include <iostream>
using namespace std;


class Heap{
    public:
    double *datos;
    int largo;
    int n_elementos = 0;

    Heap(int lar){
        this->datos = new double[lar];
        this->n_elementos = 0;
        this->largo = lar;
    }

    void insertar(double n){
        if(largo == n_elementos){
            cout<<"Arbol heap lleno"<<endl;
        }else{
            shiftright();
            datos[0] = n;
            getmax(0);
            this->n_elementos++;
        }
    }

    void shiftright(){
        for(int i = n_elementos; i>=0; i--){
            datos[i+1] = datos[i];
        }
    }

    int getmax(int index){
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

    void shiftleft_from(int index){
        for(int i = index; i<=n_elementos; i++){
            datos[i] = datos[i+1];
        }
    }

    double eliminar(double entrada){
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

    double buscar(double entrada){
        for(int i = 0; i<n_elementos;i++){
            if(entrada == this->datos[i]){
                return this->datos[i];
            };
        }
        return -1;
    };

    void mostrar(){
        for(int i = 0; i<n_elementos;i++){
            cout<<this->datos[i]<<" ";
        }
    }
};

