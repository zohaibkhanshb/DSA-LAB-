#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
private:
    BSTNode* root;

    void insert(BSTNode*& node, int value) {
        if (node == NULL) {
            node = new BSTNode(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void inorder(BSTNode* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        insert(root, value);
    }

    void traverse() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(10);
    bst.insert(25);
    bst.traverse();
    return 0;
}
