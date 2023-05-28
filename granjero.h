
#ifndef GRANJERO_H
#define GRANJERO_H
#include "tablero.h"
#include <QLabel>

class granjero{
public:
    QLabel * granjeroLabel;
    tablero * tab;
    double dinero;
    int cargaArbolTipo;
    bool cargaEspantajaros;
    std::string nombre;
    granjero();
    int verificarPosicion();

};
#endif // GRANJERO_H
