#include "ARJ.h"

void RBTree::initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
}

void RBTree::inOrderHelper(NodePtr node) {
    if (node != TNULL) {
        inOrderHelper(node->left);
        cout<<node->data<<" ";
        inOrderHelper(node->right);
    }
}

NodePtr RBTree::searchTreeHelper(NodePtr node, double key) {
    if (node == TNULL || key == node->data) {
        return node;
    }
    if (key < node->data) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

void RBTree::rbTransplant(NodePtr u, NodePtr v){
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left){
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// fix the red-black tree
void RBTree::fixInsert(NodePtr k){
    NodePtr u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left; // uncle
            if (u->color == 1) {
                // case 3.1
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    // case 3.2.2
                    k = k->parent;
                    rightRotate(k);
                }
                // case 3.2.1
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right; // uncle

            if (u->color == 1) {
                // mirror case 3.1
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    // mirror case 3.2.2
                    k = k->parent;
                    leftRotate(k);
                }
                // mirror case 3.2.1
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = 0;
}

RBTree::RBTree(int *a, int *b, int *c, int *d, double *e) {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
    this->t_crecer = a;
    this->t_produ_frut = b;
    this->n_produ_frut = c;
    this->costo = d;
    this->precio_fruto = e;
}

// In-Order traversal
// Left Subtree -> Node -> Right Subtree
void RBTree::inorder() {
    inOrderHelper(this->root);
}

// search the tree for the key k
// and return the corresponding node
NodePtr RBTree::searchTree(double k) {
    return searchTreeHelper(this->root, k);
}

// find the node with the minimum key
NodePtr RBTree::minimum(NodePtr node) {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

// find the node with the maximum key
NodePtr RBTree::maximum(NodePtr node) {
    while (node->right != TNULL) {
        node = node->right;
    }
    return node;
}

// find the successor of a given node
NodePtr RBTree::successor(NodePtr x) {
    // if the right subtree is not null,
    // the successor is the leftmost node in the
    // right subtree
    if (x->right != TNULL) {
        return minimum(x->right);
    }

    // else it is the lowest ancestor of x whose
    // left child is also an ancestor of x.
    NodePtr y = x->parent;
    while (y != TNULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

// find the predecessor of a given node
NodePtr RBTree::predecessor(NodePtr x) {
    // if the left subtree is not null,
    // the predecessor is the rightmost node in the
    // left subtree
    if (x->left != TNULL) {
        return maximum(x->left);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

// rotate left at node x
void RBTree::leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// rotate right at node x
void RBTree::rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RBTree::insert(double key) {
    // Ordinary Binary Search Insertion
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1; // new node must be red

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    // if new node is a root node, simply return
    if (node->parent == nullptr){
        node->color = 0;
        return;
    }

    // if the grandparent is null, simply return
    if (node->parent->parent == nullptr) {
        return;
    }

    // Fix the tree
    fixInsert(node);
}

NodePtr RBTree::getRoot(){
    return this->root;
}


