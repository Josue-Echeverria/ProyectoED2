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
    int *costo;
    int perdidos= 0;
    int vendidos= 0;
    int n_elementos= 0;
    double *precio_fruto;
    double vender(int);
    void comer(int);

    RBTree(int *a, int *b, int *c, int *d, double *e);
    void insertValue(double);
    void deleteValue(double);
    double del_min();
    void merge(RBTree);
    void inorder();
    void preorder();
};
#endif
