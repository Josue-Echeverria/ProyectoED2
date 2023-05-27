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
    int perdidos = 0;
    int vendidos = 0;
    int n_elementos = 0;
    double vender(int);
    void comer(int);

    Heap(int lar,int *a, int *b, int *c, double *d, double *e);

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
