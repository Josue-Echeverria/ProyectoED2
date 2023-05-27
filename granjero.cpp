#include "granjero.h"

granjero::granjero(){
    this->cargaArbolTipo = 0;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
    this->dinero = 500;
    this->cargaEspantajaros = false;
}
int granjero::verificarPosicion(){
    int x = granjeroLabel->x();
    int y = granjeroLabel->y();
    int plaga = 0;
    if(tab->Tablero[x][y]->plaga != 0){
        plaga = tab->Tablero[x][y]->plaga;
        tab->Tablero[x][y]->plaga = 0;
    }
    return plaga;
};
