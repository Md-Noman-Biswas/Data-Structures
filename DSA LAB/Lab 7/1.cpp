#include <iostream>
using namespace std;

const int MAX_NODES = 100; 

struct Node {
  char item;
};

Node tree[MAX_NODES];

void insertNode(int index, char value) {
  if (index >= MAX_NODES) return;
  if (tree[index].item == '\0') {
    tree[index].item = value;
    tree[2 * index + 1].item = '\0'; 
    tree[2 * index + 2].item = '\0';
  }
}

void preorderTraversal(int index) {
  if (index >= MAX_NODES || tree[index].item == '\0') return;
  cout << tree[index].item << " "; 
  preorderTraversal(2 * index + 1); 
  preorderTraversal(2 * index + 2); 
}

void printNodes() {
  cout << "Nodes: ";
  for (int i = 0; i < MAX_NODES; ++i) {
    if (tree[i].item != '\0') {
      cout << tree[i].item << " ";
    }
  }
  cout << endl;
}

int main() {
    insertNode(0, 'A');
    insertNode(1, 'B');
    insertNode(2, 'C');
    insertNode(3, 'D');
    insertNode(4, 'E');
    insertNode(5, 'F');
    insertNode(6, 'G');
    insertNode(9, 'H');
    insertNode(12, 'I');
    insertNode(19, 'J');

    printNodes();

  cout << "Preorder traversal: ";
  preorderTraversal(0);
  cout << endl;

  return 0;
}
