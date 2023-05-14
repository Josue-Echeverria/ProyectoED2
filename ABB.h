#include <iostream>
using namespace std;


class Node {
public:
    int key;
    Node* left, * right;
};


typedef struct Node ABB;


ABB* newABB(int item) {
    ABB* temp = new ABB;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(ABB* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void insertABB(ABB*& root, int key)
{
    ABB* toinsertABB = newABB(key);
    ABB* curr = root;
    ABB* prev = NULL;

    while (curr != NULL) {
        prev = curr;
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (prev == NULL) {
        prev = toinsertABB;
        root = prev;
    }

    else if (key < prev->key) {
        prev->left = toinsertABB;
    }

    else {
        prev->right = toinsertABB;
    }
}

ABB* getmin(ABB* root)
{
    ABB* curr = root;

    while (curr && curr->left) {
        curr = curr->left;
    }

    return curr;
}

ABB* deleteABB(ABB* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteABB(root->left, key);

    else if (key > root->key)
        root->right = deleteABB(root->right, key);
    else {
        if (root->left == NULL) {
            ABB* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) {
            ABB* temp = root->left;
            delete(root);
            return temp;
        }

        ABB* temp = getmin(root->right);

        root->key = temp->key;
        root->right = deleteABB(root->right, temp->key);
    }
    return root;
}

