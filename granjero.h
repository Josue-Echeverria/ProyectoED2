
#ifndef GRANJERO_H
#define GRANJERO_H
#include "tablero.h"
#include <QLabel>

class granjero{
    QLabel * granjeroLabel;
    tablero * tab;
    double dinero;
    bool cargaArbol;
    bool cargaEspantajaros;
    granjero(QLabel * granjeroLabel, tablero * tab){
        this->granjeroLabel = granjeroLabel;
        this->tab = tab;
        this->cargaArbol = false;
        this->dinero = 500;
        this->cargaEspantajaros = false;
    }

    int verificarPosicion(){
        int x = granjeroLabel->x();
        int y = granjeroLabel->y();
        int plaga = 0;
        if(tab->Tablero[x][y]->plaga != 0){
            plaga = tab->Tablero[x][y]->plaga;
            tab->Tablero[x][y]->plaga = 0;
        }
        return plaga;
    };
};
#endif // GRANJERO_H
