
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

    granjero(QLabel * granjeroLabel, tablero * tab);
    int verificarPosicion();

};
#endif // GRANJERO_H
