#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <QThread>
#include <QRandomGenerator>
#include "node.h"
using namespace std;


#include <queue>

class NodoArbol{
public:
    double info;
    NodoArbol *izq, *der;
    NodoArbol( ){ izq = der = NULL; }
    NodoArbol(double dato)
    { info = dato; izq = der = NULL; }
};

class ABB {

//private:
public:
    NodoArbol *raiz;

    int *t_crecer;
    int *t_produ_frut;
    int *n_produ_frut;
    int *costo;
    double *precio_fruto;

    ABB(int *a, int *b, int *c, int *d, double *e);


    ~ABB(){
    }


    bool busca (double valor);

    NodoArbol* encuentraPadre (double valor);

    void meterABB (double valor);

    NodoArbol* predecesor(NodoArbol *actual);

    NodoArbol* sucesor (NodoArbol *actual) ;

    void sacarABB(double valor);

    void despliegaAncestros (int valor);

    void despliegaMenor();

    void despliegaMayor();

    int cuentaPositivos(NodoArbol *r);

    int sumaPositivos(NodoArbol *r);

    void inorder(NodoArbol *r);

    void alturaArbol();

    int altura(NodoArbol *r);

    void despliegaNivelxNivel();

};

#endif
