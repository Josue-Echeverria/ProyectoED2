#ifndef HEAP_H
#define HEAP_H

#include <QThread>
#include <QRandomGenerator>
#include <iostream>
using namespace std;


class Heap{
    public:
    int t_crecer = -1;
    double *datos;
    int largo;
    int n_elementos = 0;

    Heap(int lar);

    void insertar(double n);

    void shiftright();

    int getmax(int index);

    void shiftleft_from(int index);

    double eliminar(double entrada);

    double buscar(double entrada);

    void mostrar();
};
#endif
