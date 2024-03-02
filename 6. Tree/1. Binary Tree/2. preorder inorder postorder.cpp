#include <iostream>
using namespace std;

struct Node {
  char item;
  Node* left;
  Node* right;
};


void inorderTraversal(Node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  cout << root->item << " -> ";
  inorderTraversal(root->right);
}


void preorderTraversal(Node* root) {
  if (root == NULL) return;
  cout << root->item << " -> ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void postorderTraversal(Node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->item << " -> ";
}


Node* createNode(char value) {
  Node* newNode = new Node();
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
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
  

  cout << "Inorder traversal" << endl;
  inorderTraversal(root);

  cout << "\nPreorder traversal" << endl;
  preorderTraversal(root);

  cout << "\nPostorder traversal" << endl;
  postorderTraversal(root);

  return 0;
}
