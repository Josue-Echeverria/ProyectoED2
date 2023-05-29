#ifndef TABLERO_H
#define TABLERO_H
#include "ABB_thread.h"
#include "ARJ_thread.h"
#include "avl_thread.h"
#include "Heap_Thread.h"

class casilla{
public:
    int x;
    int y;
    int arbol;   // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
    int n_elementos= 0;
    int perdidos = 0;
    int vendidos= 0;
    ABB_Thread * Abb;
    ARJ_thread * Arj;
    ABB_Thread * Avl;
    Heap_Thread * Heap;
    int cantFrutos;
    int plaga; // 0 = vacio, 1 = oveja, 2 = cuervo, 3 = plaga.
    bool espantaPaj;
    bool granjero;
    casilla(int x, int y){
        this->x = x;
        this->y = y;
        this->arbol = 0;
        this->plaga = 0;
        this->granjero = false;
        this->Abb = NULL;
        this->Arj = NULL;
        this->Avl = NULL;
        this->Heap = NULL;
        this->espantaPaj = false;
        this->granjero = false;
    }
};

class tablero{
    public: casilla *Tablero[8][8];
    tablero(){
        int a = 60;
        int b = 80;
        for(int i = 0; i < 8; i++){
            for(int y = 0; y < 8; y++){
                Tablero[i][y] = new casilla(a, b);
                a += 125;
            }
            b += 77;
            a = 60;
        }
    }

    casilla * casillaEnPos(int x, int y){
        return Tablero[x][y];
    }

    void agregarPlaga(int x, int y, int numPlaga){
        Tablero[x][y]->plaga = numPlaga;
    }
    void modificarArbol(int x, int y, int numArbol,int *t_crecer,int *t_para_cosechar,int *cosecha_n,double *costo, double *precio_x_fruta,QTableWidget *tabla,double * plata, int n, QLabel *imagen){
        Tablero[x][y]->arbol = numArbol;
        switch (numArbol) {// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        case 1:
            Tablero[x][y]->Abb = new ABB_Thread(t_crecer,t_para_cosechar,cosecha_n,costo,precio_x_fruta,tabla,x,y,plata,true,&Tablero[x][y]->n_elementos,&Tablero[x][y]->perdidos,&Tablero[x][y]->vendidos,imagen);
            if(n != -1)
                Tablero[x][y]->Abb->produce_n(n);
            Tablero[x][y]->Abb->start();
            break;
        case 2:
            Tablero[x][y]->Arj = new ARJ_thread(t_crecer,t_para_cosechar,cosecha_n,costo,precio_x_fruta,tabla,x,y,plata,&Tablero[x][y]->n_elementos,&Tablero[x][y]->perdidos,&Tablero[x][y]->vendidos,imagen);
            if(n != -1)
                Tablero[x][y]->Arj->produce_n(n);
            Tablero[x][y]->Arj->start();
            break;
        case 3:
            Tablero[x][y]->Avl = new ABB_Thread(t_crecer,t_para_cosechar,cosecha_n,costo,precio_x_fruta,tabla,x,y,plata,false,&Tablero[x][y]->n_elementos,&Tablero[x][y]->perdidos,&Tablero[x][y]->vendidos,imagen);
            if(n != -1)
                Tablero[x][y]->Avl->produce_n(n);

            Tablero[x][y]->Avl->start();
            break;
        case 4:
            Tablero[x][y]->Heap = new Heap_Thread(20,t_crecer,t_para_cosechar,cosecha_n,costo,precio_x_fruta,tabla,x,y,plata,&Tablero[x][y]->n_elementos,&Tablero[x][y]->perdidos,&Tablero[x][y]->vendidos,imagen);
            if(n != -1)
                Tablero[x][y]->Heap->produce_n(n);

            Tablero[x][y]->Heap->start();
            break;
        }
    }
};

#endif // TABLERO_H
