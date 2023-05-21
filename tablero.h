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
    ABB_Thread * Abb;
    ARJ_thread * Arj;
    AVL_Thread * Avl;
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

    void modificarArbol(int x, int y, int numArbol){
        Tablero[x][y]->arbol = numArbol;
        switch (numArbol) {
        case 1:
            //Tablero[x][y]->Abb = new ABB_Thread();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }
    }
};

#endif // TABLERO_H
