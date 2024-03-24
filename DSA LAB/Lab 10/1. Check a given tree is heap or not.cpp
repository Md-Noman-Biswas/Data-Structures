#include <iostream>
#include <climits>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node* left, *right;
};

// Utility function to create a new Binary Tree Node
Node* newNode(int item) {
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


bool isMaxHeapUtil(Node* root, int min_value, int max_value) {
    if (!root) {
        return true;
    }

    if (root->data < min_value || root->data > max_value) {
        return false;
    }

    return isMaxHeapUtil(root->left, min_value, root->data - 1) &&
           isMaxHeapUtil(root->right, root->data + 1, max_value);
}


bool isMinHeapUtil(Node* root, int min_value, int max_value) {
    if (!root) {
        return true;
    }

    if (root->data < min_value || root->data > max_value) {
        return false;
    }

    return isMinHeapUtil(root->left, min_value, root->data - 1) &&
           isMinHeapUtil(root->right, root->data + 1, max_value);
}


string isHeap(Node* root) {
    int min_value = INT_MIN;
    int max_value = INT_MAX;

    if (isMaxHeapUtil(root, min_value, max_value)) {
        return "It's a heap";
    } else if (isMinHeapUtil(root, min_value, max_value)) {
        return "It's a heap";
    } else {
        return "It's not a heap";
    }
}

int main() {
    Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(25);
    root->left->left = newNode(5);
    root->left->right = newNode(15);

    cout << isHeap(root) << endl;

    return 0;
}
