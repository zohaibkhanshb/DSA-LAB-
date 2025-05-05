#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = NULL;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    void insert(TreeNode*& node, int value) {
        if (node == NULL) {
            node = new TreeNode(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void bfs() {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        insert(root, value);
    }

    void bfsTraversal() {
        bfs();
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.bfsTraversal();
    return 0;
}
