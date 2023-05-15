#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <QThread>
#include <QRandomGenerator>
#include "node.h"
using namespace std;



typedef struct Node ABB;


ABB* newABB(double item) ;
void inorder(ABB* root);
void insertABB(ABB*& root, double key);
ABB* getmin(ABB* root);
ABB* deleteABB(ABB* root, double key);


#endif
