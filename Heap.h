#ifndef HEAP_H
#define HEAP_H

#include <QThread>
#include <QRandomGenerator>
#include <iostream>
using namespace std;


class Heap{
    public:
    double *datos;
    int largo;

    int *t_crecer;
    int *t_produ_frut;
    int *n_produ_frut;
    double *costo;
    double *precio_fruto;
    int* perdidos;
    int* vendidos;
    int* n_elementos;
    double vender(int);
    void comer(int);

    Heap(int lar,int *a, int *b, int *c, double *d, double *e,int *f,int *g,int *h);

    void insertar(double n);

    void shiftright();

    int getmax(int index);

    void shiftleft_from(int index);

    double eliminar(double entrada);

    void eliminar_todo();

    int delete_random();

    double buscar(double entrada);

    void mostrar();
};
#endif
