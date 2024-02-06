#include <iostream>
using namespace std;

class BstNode{
public:
    int data;
    BstNode* left;
    BstNode* right;
};

class BinarySearchTree{
private:
    BstNode* root = NULL;

public:
    BstNode* GetNewNode(int data) {
        BstNode* newNode = new BstNode();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BstNode* InsertRecursive(BstNode* root, int data) {
        if (root == NULL) {
            return GetNewNode(data);
        } else if (data <= root->data) {
            root->left = InsertRecursive(root->left, data);
        } else {
            root->right = InsertRecursive(root->right, data);
        }
        return root;
    }

    int findMinRecursive(BstNode* root) {
        if (root == NULL) {
            cout << "Error: Tree is Empty\n";
            return -1;
        } else if (root->left == NULL) {
            return root->data;
        }
        return findMinRecursive(root->left);
    }

    int findMaxRecursive(BstNode* root) {
        if (root == NULL) {
            cout << "Error: Tree is Empty\n";
            return -1;
        } else if (root->right == NULL) {
            return root->data;
        }
        return findMaxRecursive(root->right);
    }

    void Insert(int data) {
        root = InsertRecursive(root, data);
    }

    int findMin() {
        return findMinRecursive(root);
    }

    int findMax() {
        return findMaxRecursive(root);
    }
};

int main() {
    BinarySearchTree bst;

    bst.Insert(15);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(30);

    cout << "Min element: " << bst.findMin() << "\n";
    cout << "Max element: " << bst.findMax() << "\n";

    return 0;
}
