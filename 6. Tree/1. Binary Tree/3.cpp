#include <iostream>
#include <stack>
using namespace std;

struct Node {
  char item;
  Node* left;
  Node* right;
};


void preorderTraversal(Node* root) {
  stack<Node*> s;
  s.push(root);
  while (!s.empty()) {
    Node* current = s.top();
    //if(current != nullptr) cout << current->item << "\n";
    s.pop();
    if (current != nullptr) {
      cout << current->item << " -> ";
      s.push(current->right);
      s.push(current->left);
    }
  }
}


Node* createNode(char value) {
  Node* newNode = new Node();
  newNode->item = value;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

Node* insertLeft(Node* root, char value) {
  root->left = createNode(value);
  return root->left;
}

Node* insertRight(Node* root, char value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  Node* root = createNode('A');
  Node* nodeB = insertLeft(root, 'B');
  Node* nodeC = insertRight(root, 'C');

  Node* nodeD = insertLeft(nodeB, 'D');
  Node* nodeE = insertRight(nodeB, 'E');
  Node* nodeH = insertLeft(nodeE, 'H');
  Node* nodeJ = insertLeft(nodeH, 'J');

  Node* nodeF = insertLeft(nodeC, 'F');
  Node* nodeG = insertRight(nodeC, 'G');
  Node* nodeI = insertRight(nodeF, 'I');


  cout << "\nPreorder traversal" << endl;
  preorderTraversal(root);
}
