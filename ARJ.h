#ifndef ARJ_H
#define ARJ_H
#include <iostream>
#include <QThread>
#include <QRandomGenerator>
#include "node.h"
using namespace std;


enum Color {RED, BLACK, DOUBLE_BLACK};

class RBTree {

private:
    Node *root;
protected:
    void rotateLeft(Node *&);
    void rotateRight(Node *&);
    void fixInsertRBTree(Node *&);
    void fixDeleteRBTree(Node *&);
    void inorderBST(Node *&);
    void preorderBST(Node *&);
    int getColor(Node *&);
    void setColor(Node *&, int);
    Node *minValueNode(Node *&);
    Node *maxValueNode(Node *&);
    Node* insertBST(Node *&, Node *&);
    Node* deleteBST(Node *&, double);
    int getBlackHeight(Node *);
public:
    int *t_crecer;
    int *t_produ_frut;
    int *n_produ_frut;
    double *costo;
    int* perdidos;
    int* vendidos;
    int* n_elementos;
    double *precio_fruto;
    double vender(int);
    void comer(int);

    RBTree(int *a, int *b, int *c, double *d, double *e,int *f,int *g,int *h);
    void insertValue(double);
    void deleteValue(double);
    double del_min();
    void merge(RBTree);
    void inorder();
    void preorder();
};
#endif
