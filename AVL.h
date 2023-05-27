#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <QThread>
#include <QThread>
#include "ABB.h"
#include <QRandomGenerator>
#include <queue>

using namespace std;

class AVL;

// Clase Nodo de Arbol AVL:
class node {
  public:

   struct node *left;
   double data;
   int height;
   struct node *right;
};

class AVL {

   public:
   struct node *root;
   AVL()
   {
       this->root = NULL;
   }


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

   AVL(int *a, int *b, int *c, int *d, double *e);
   ~AVL() { }
   struct node *insert(struct node *&r, double data);

   struct node *deleteNode(struct node *&p, double data);

   bool Vacio(node *r) { return r==NULL; }

   bool EsHoja(node *r) { return !r->right && !r->left;}

   int calheight(struct node *p);

   void InOrden();

   struct node *inpre(struct node *p);

   struct node *insuc(struct node *p);
   double del_min();
  private:
   // Funciones de equilibrado:



      struct node *llrotation(struct node *n);
      struct node *rrrotation(struct node *n);
      struct node *rlrotation(struct node *n);
      struct node *lrrotation(struct node *n);

      node *Buscar(const double dat);
};

#endif
