#include "granjero.h"

granjero::granjero(QLabel * granjeroLabel, tablero * tab){
    this->granjeroLabel = granjeroLabel;
    this->tab = tab;
    this->cargaArbol = false;
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
