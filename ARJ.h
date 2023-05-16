#ifndef ARJ_H
#define ARJ_H
#include <iostream>
#include <QThread>
#include <QRandomGenerator>
#include "node.h"
using namespace std;
/*
struct Node {
	double data; // holds the key
	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
	int color; // 1 -> Red, 0 -> Black
};

typedef Node *NodePtr;
*/
class RBTree {
    int t_crecer = -1;

private:
	NodePtr root;
	NodePtr TNULL;

    void initializeNULLNode(NodePtr node, NodePtr parent);

    void inOrderHelper(NodePtr node);

    NodePtr searchTreeHelper(NodePtr node, double key);

    void rbTransplant(NodePtr u, NodePtr v);

	// fix the red-black tree
    void fixInsert(NodePtr k);
public:
    RBTree();

	// In-Order traversal
	// Left Subtree -> Node -> Right Subtree
    void inorder() ;

	// search the tree for the key k
	// and return the corresponding node
    NodePtr searchTree(double k) ;

	// find the node with the minimum key
    NodePtr minimum(NodePtr node) ;

	// find the node with the maximum key
    NodePtr maximum(NodePtr node) ;

	// find the successor of a given node
    NodePtr successor(NodePtr x) ;

	// find the predecessor of a given node
    NodePtr predecessor(NodePtr x) ;

	// rotate left at node x
    void leftRotate(NodePtr x) ;

	// rotate right at node x
    void rightRotate(NodePtr x) ;

    void insert(double key) ;

    NodePtr getRoot() ;



};
#endif
