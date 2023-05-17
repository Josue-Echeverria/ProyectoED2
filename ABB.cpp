#include "ABB.h"

ABB::ABB(int *a, int *b, int *c, int *d, double *e){
    raiz = NULL;
    this->t_crecer = a;
    this->t_produ_frut = b;
    this->n_produ_frut = c;
    this->costo = d;
    this->precio_fruto = e;
}


bool ABB::busca (double valor){
    NodoArbol * p = raiz;
    while (p != NULL)
    {
        if (p->info == valor)
            return true;
        else
            p=(p->info > valor? p->izq: p->der);
    }
    return false;
}


NodoArbol* ABB::encuentraPadre (double valor){
    NodoArbol *padre, *hijo;
    hijo = raiz;
    padre = NULL;
    while (hijo != NULL && hijo->info != valor){
        padre = hijo;
        hijo = (hijo->info > valor ? hijo->izq : hijo->der);
    }
    return padre;
}


void ABB::meterABB (double valor){
    NodoArbol *padre = encuentraPadre(valor);
    NodoArbol *nuevo = new NodoArbol (valor);
    if(padre == NULL) //Agrega el primer nodo del árbol
        raiz = nuevo;
    else
    { //Agrega un nodo hoja
        if ( padre->info > valor )
            padre->izq = nuevo;
        else
            padre->der = nuevo;
    }
}


NodoArbol* ABB::predecesor(NodoArbol *actual){
    NodoArbol *p = actual->izq;
    while (p->der != NULL)
        p = p->der;
    return p;
}


NodoArbol* ABB::sucesor (NodoArbol *actual) {
    NodoArbol *p = actual->der;
    while (p->izq != NULL)
        p = p->izq;
    return p;
}


void ABB::sacarABB(double valor) {
    NodoArbol *padre = encuentraPadre(valor);
    NodoArbol *nodoABorrar;
    if (padre == NULL)
        nodoABorrar = raiz;
    else
        nodoABorrar=(padre->info > valor? padre->izq : padre->der);
    //Encontrar substituto cuando el nodo a borrar tiene 2 hijos
    if (nodoABorrar->izq != NULL && nodoABorrar->der != NULL)
    {
        NodoArbol *substituto = predecesor(nodoABorrar);
        double nuevovalor = substituto->info;
        sacarABB (substituto->info);
        nodoABorrar->info = nuevovalor;
    }
    else if (padre == NULL)
    { //Borra nodo raíz el cual solo tiene un hijo
        if (nodoABorrar->der == NULL)
            raiz = nodoABorrar->izq;
        else
            raiz = nodoABorrar->der;
    }
    else if (padre->info > valor) //Borra nodo con 0 o 1 hijo
        if (nodoABorrar->izq == NULL)
            padre->izq = nodoABorrar->der;
        else
            padre->izq = nodoABorrar->izq;
        else if (nodoABorrar->der == NULL)
            padre->der =nodoABorrar->izq;
        else
            padre->der = nodoABorrar->der;
}


void ABB::alturaArbol(){
    cout << "ALTURA: ";
    cout << altura(raiz);
}


void ABB::inorder(NodoArbol *r){
    if (r != NULL){
        inorder(r->izq);
            std::cout<<r->info<< " "<<std::endl;
        inorder(r->der);
    }
}


int ABB::altura(NodoArbol *r){
    if (r==NULL){
        return 0;
    }
    int i=altura(r->izq);
    int d=altura(r->der);
    if (i > d){
        return 1 + i;
    }
    else
        return 1 + d;
}
