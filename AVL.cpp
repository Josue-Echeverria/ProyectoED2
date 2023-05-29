#include "AVL.h"
void AVL::comer(int n){
    while(n > 0 & n_elementos > 0){
        if(this->del_min() != -1){
            n--;
            this->perdidos++;
        }else
            break;
    }
}

double AVL::vender(int n){
    double acumulador = 0;
    if(n == -1){
        acumulador = this->n_elementos**this->precio_fruto;
        this->root = NULL;
        this->vendidos += this->n_elementos;
        this->n_elementos = 0;
        return acumulador;
    }
    while(n > 0 & n_elementos > 0){
        if(this->del_min() != -1){
            std::cout<<"\nLo elimine"<<std::endl;
            acumulador += *this->precio_fruto;
            n--;
            this->vendidos++;
        }else
            break;
    }
    return acumulador;
}

struct node *AVL::inpre(struct node *p)
{
    while (p->right != NULL)
        p = p->right;
    return p;
}

struct node *AVL::insuc(struct node *p){
    while (p->left != NULL)
        p = p->left;
    return p;
}

double AVL::del_min(){
   node *min = insuc(this->root);
   if(min!= NULL){
        //double temp = Buscar(min->data)->data;
        deleteNode(this->root,min->data);
        this->n_elementos--;
        return 1;
   }
   return -1;
}

int height(node *N)
{
   if (N == NULL)
        return 0;
   return N->height;
}

int bf(struct node *n){
   if (n->left && n->right){
        return n->left->height - n->right->height;
   }else if (n->left && n->right == NULL){
        return n->left->height;
   }else if (n->left == NULL && n->right){
        return -n->right->height;
   }
}

struct node *llrotation(struct node *n){
   struct node *p;
   struct node *tp;
   p = n;
   tp = p->left;
   p->left = tp->right;
   tp->right = p;

   return tp;
}



node *rrrotation(node *y)
{
   node *x = y->left;
   node *T2 = x->right;

   // Perform rotation
   x->right = y;
   y->left = T2;

   // Update heights
   y->height = max(height(y->left),
                   height(y->right)) + 1;
   x->height = max(height(x->left),
                   height(x->right)) + 1;

   // Return new root
   return x;
}

struct node * rlrotation(struct node *n)
{
   struct node *p;
   struct node *tp;
   struct node *tp2;
   p = n;
   tp = p->right;
   tp2 = p->right->left;

   p->right = tp2->left;
   tp->left = tp2->right;
   tp2->left = p;
   tp2->right = tp;

   return tp2;
}

struct node *lrrotation(struct node *n)
{
   struct node *p;
   struct node *tp;
   struct node *tp2;
   p = n;
   tp = p->left;
   tp2 = p->left->right;

   p->left = tp2->right;
   tp->right = tp2->left;
   tp2->right = p;
   tp2->left = tp;

   return tp2;
}

node *AVL::insert(node *&r, double data){
   if (r == NULL){
        struct node *n;
        n = new struct node;
        n->data = data;
        r = n;
        r->left = r->right = NULL;
        r->height = 1;
        return r;
   } else {
        if (data < r->data)
          r->left = insert(r->left, data);
        else
          r->right = insert(r->right, data);
   }
   //r->height = calheight(r);

   if (bf(r) == 2 && bf(r->left) == 1){
        r = llrotation(r);
   }
   else if (bf(r) == -2 && bf(r->right) == -1){
        r = rrrotation(r);
   }
   else if (bf(r) == -2 && bf(r->right) == 1){
        r = rlrotation(r);
   }
   else if (bf(r) == 2 && bf(r->left) == -1){
        r = lrrotation(r);
   }
   return r;

}

struct node* AVL::deleteNode(struct node *&p, double data){
   if (p->left == NULL && p->right == NULL){
        if (p == this->root)
          this->root = NULL;
        p = NULL;
        delete p;
        return NULL;
   }
   struct node *t;
   struct node *q;
   if (p->data < data){
        p->right = deleteNode(p->right, data);
   }
   else if (p->data > data){
        p->left = deleteNode(p->left, data);
   }
   else{
        if (p->left != NULL){
          q = inpre(p->left);
          p->data = q->data;
          p->left = deleteNode(p->left, q->data);
        } else {
          q = insuc(p->right);
          p->data = q->data;
          p->right = deleteNode(p->right, q->data);
        }
   }

   if (bf(p) == 2 && bf(p->left) == 1){
        p = llrotation(p);
   }else if (bf(p) == 2 && bf(p->left) == -1){
        p = lrrotation(p);
   }else if (bf(p) == 2 && bf(p->left) == 0){
        p = llrotation(p);
   }else if (bf(p) == -2 && bf(p->right) == -1){
        p = rrrotation(p);
   }else if (bf(p) == -2 && bf(p->right) == 1){
        p = rlrotation(p);
   }else if (bf(p) == -2 && bf(p->right) == 0){
        p = llrotation(p);
   }
   return p;
}

node *AVL::Buscar(const double dat)
{
   node *actual = root;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->data) return actual; // dato encontrado
      else if(dat > actual->data) actual = actual->right; // Seguir
      else if(dat < actual->data) actual = actual->left;
   }
   return NULL; // No está en árbol
}

void Mostrar(node *nodo)
{
   if(nodo == NULL){
      return;
   }

   Mostrar(nodo->left);
   std::cout << nodo->data << std::endl;
   Mostrar(nodo->right);
}

void AVL::InOrden()
{
   Mostrar(this->root);
}


struct node *AVL::llrotation(struct node *n){
   struct node *p;
   struct node *tp;
   p = n;
   tp = p->left;

   p->left = tp->right;
   tp->right = p;

   return tp;
}

struct node *AVL::rrrotation(struct node *n){
   struct node *p;
   struct node *tp;
   p = n;
   tp = p->right;

   p->right = tp->left;
   tp->left = p;

   return tp;
}

struct node *AVL::rlrotation(struct node *n)
{
   struct node *p;
   struct node *tp;
   struct node *tp2;
   p = n;
   tp = p->right;
   tp2 = p->right->left;

   p->right = tp2->left;
   tp->left = tp2->right;
   tp2->left = p;
   tp2->right = tp;

   return tp2;
}

struct node *AVL::lrrotation(struct node *n)
{
   struct node *p;
   struct node *tp;
   struct node *tp2;
   p = n;
   tp = p->left;
   tp2 = p->left->right;

   p->left = tp2->right;
   tp->right = tp2->left;
   tp2->right = p;
   tp2->left = tp;

   return tp2;
}

AVL::AVL(int *a, int *b, int *c, double *d, double *e) {
   root = NULL;
   this->n_elementos = 0;

   this->t_crecer = a;
   this->t_produ_frut = b;
   this->n_produ_frut = c;
   this->costo = d;
   this->precio_fruto = e;}
