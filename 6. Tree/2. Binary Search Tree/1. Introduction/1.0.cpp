#include <iostream>
using namespace std;

const int MAX_NODES = 100;

struct Node {
    int data;
};

Node tree[MAX_NODES];

void insertNode(int index, int value) {
    if (index >= MAX_NODES) return;
    if (tree[index].data == 0) {
        tree[index].data = value;
        tree[2 * index + 1].data = 0; // Left child
        tree[2 * index + 2].data = 0; // Right child
    } else if (value <= tree[index].data) {
        insertNode(2 * index + 1, value); // Insert in the left subtree
    } else {
        insertNode(2 * index + 2, value); // Insert in the right subtree
    }
}

void inorderTraversal(int index) {
    if (index >= MAX_NODES || tree[index].data == 0) return;
    inorderTraversal(2 * index + 1); // Traverse left subtree
    cout << tree[index].data << " "; // Print the current node
    inorderTraversal(2 * index + 2); // Traverse right subtree
}

void printNodes() {
    cout << "Nodes: ";
    for (int i = 0; i < MAX_NODES; ++i) {
        if (tree[i].data != 0) {
            cout << tree[i].data << " ";
        }
    }
    cout << endl;
}

int main() {
    insertNode(0, 15);
    insertNode(0, 10);
    insertNode(0, 20);
    insertNode(0, 25);
    insertNode(0, 8);
    insertNode(0, 12);

    printNodes();

    cout << "Inorder traversal: ";
    inorderTraversal(0);
    cout << endl;

    return 0;
}
