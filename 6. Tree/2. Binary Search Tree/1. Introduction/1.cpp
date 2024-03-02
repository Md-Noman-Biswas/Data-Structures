#include <iostream>
#include <vector>
using namespace std;

// Definition of Node for Binary search tree
struct BstNode {
    int data;
    int leftChildIndex;
    int rightChildIndex;
};

class BinarySearchTree {
private:
    vector<BstNode> nodes;

public:
    BinarySearchTree() {
        // Initialize the root node with empty values
        nodes.push_back({0, -1, -1});
    }

    // Function to insert data in BST array and return the index of the inserted node
    int insert(int data, int rootIndex) {
        if (nodes[rootIndex].data == 0) { // empty node
            int newIndex = nodes.size();
            nodes.push_back({data, -1, -1});
            return newIndex;
        } else if (data <= nodes[rootIndex].data) {
            int leftChildIndex = nodes[rootIndex].leftChildIndex;
            int newLeftIndex = insert(data, leftChildIndex);
            nodes[rootIndex].leftChildIndex = newLeftIndex;
        } else {
            int rightChildIndex = nodes[rootIndex].rightChildIndex;
            int newRightIndex = insert(data, rightChildIndex);
            nodes[rootIndex].rightChildIndex = newRightIndex;
        }
        return rootIndex;
    }

    // Function to search an element in BST array, returns true if element is found
    bool search(int data, int rootIndex) {
        if (rootIndex == -1 || nodes[rootIndex].data == 0) {
            return false;
        } else if (nodes[rootIndex].data == data) {
            return true;
        } else if (data <= nodes[rootIndex].data) {
            return search(data, nodes[rootIndex].leftChildIndex);
        } else {
            return search(data, nodes[rootIndex].rightChildIndex);
        }
    }

    // Function to print in-order traversal of the BST
    void printInOrder(int rootIndex) {
        if (rootIndex != -1 && nodes[rootIndex].data != 0) {
            printInOrder(nodes[rootIndex].leftChildIndex);
            cout << nodes[rootIndex].data << " ";
            printInOrder(nodes[rootIndex].rightChildIndex);
        }
    }
};

int main() {
    BinarySearchTree bst;

    /* Code to test the logic */
    bst.insert(15, 0);
    bst.insert(10, 0);
    bst.insert(20, 0);
    bst.insert(25, 0);
    bst.insert(8, 0);
    bst.insert(12, 0);

    // Print in-order traversal of the BST
    cout << "In-order traversal: ";
    bst.printInOrder(0);
    cout << endl;

    // Ask user to enter a number.
    int number;
    cout << "Enter number to be searched\n";
    cin >> number;

    // If number is found, print "FOUND"
    if (bst.search(number, 0)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
