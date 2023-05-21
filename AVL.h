#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <QThread>
#include <QThread>
#include <QRandomGenerator>
using namespace std;

class AVL;

// Clase Nodo de Arbol AVL:
class Nodo {
  public:
   // Constructor:
   Nodo(const double dat, Nodo *pad=NULL, Nodo *izq=NULL, Nodo *der=NULL) :
     dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}
   // Miembros:
   double dato;
   int FE;
   Nodo *izquierdo;
   Nodo *derecho;
   Nodo *padre;
   friend class AVL;
};

class AVL {

  private:
   enum {IZQUIERDO, DERECHO};
   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:

   int *t_crecer;
   int *t_produ_frut;
   int *n_produ_frut;
   int *costo;
   double *precio_fruto;
   double vender(int);
   void comer(int);

   int n_elementos= 0;
   int perdidos= 0;
   int vendidos= 0;
   // Constructor y destructor básicos:
   AVL(int *a, int *b, int *c, int *d, double *e);
   ~AVL() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const double dat);
   // Borrar un elemento del árbol:
   void Borrar(const double dat);
   // Función de búsqueda:
   Nodo *Buscar(const double dat);
   // Comprobar si el árbol está vacío:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un dato:
   int Altura(const int dat);
   // Devolver referencia al dato del nodo actual:
   double &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(double&, double) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&, int) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&, int) , Nodo *nodo=NULL, bool r=true);
   Nodo *get_min(Nodo *node);
   double del_min();
  private:
   // Funciones de equilibrado:
   void Equilibrar(Nodo *nodo, int, bool);
   void RSI(Nodo* nodo);
   void RSD(Nodo* nodo);
   void RDI(Nodo* nodo);
   void RDD(Nodo* nodo);
   // Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);

};
void Mostrar(double &d, double FE);

#endif // AVL_H
