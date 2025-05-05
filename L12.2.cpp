#include <iostream>
using namespace std;

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode* insert(AVLNode* node, int value) {
        if (node == NULL) {
            return new AVLNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inorder(AVLNode* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVL() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void traverse() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVL avl;
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
    avl.insert(25);
    avl.traverse();
    return 0;
}
