#include <iostream>
#include <stack>
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

    void dfs(TreeNode* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        dfs(node->left);
        dfs(node->right);
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        insert(root, value);
    }

    void dfsTraversal() {
        dfs(root);
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
    tree.dfsTraversal();
    return 0;
}
