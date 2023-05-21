#ifndef NODE_H
#define NODE_H
class Node {
public:
  //  double key;
 //   Node* left, * right;
    double data; // holds the key
    Node *parent; // pointer to the parent
    Node *left; // pointer to left child
    Node *right; // pointer to right child
    int color; // 1 -> Red, 0 -> Black

    explicit Node(double);


};
typedef Node *NodePtr;


#endif // NODE_H
