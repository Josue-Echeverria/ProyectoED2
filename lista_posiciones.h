#ifndef LISTA_POSICIONES_H
#define LISTA_POSICIONES_H
#include <iostream>

class nodo{
    int x;
    int y;
    nodo *siguiente;
    nodo(int x, int y){
        this->x = x;
        this->y = y;
        this->siguiente = NULL;
    }
};

class Lista_posiciones
{
public:
    nodo *primero;
    Lista_posiciones(){
        primero = NULL;
    };
    void insertar(int,int);
    void eliminar(int);
};

#endif // LISTA_POSICIONES_H
