#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* NewNode(char value){
    Node* temp = new Node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    //return temp;
}

Node* insert_left(Node* node, char value){
    node->left = NewNode(value);
    return node->left;
}

Node* insert_right(Node* node, char value){
    node->right = NewNode(value);
    return node->right;
}

void inorder(Node* node){
    if(node == NULL) return;
    inorder(node->left);
    cout << node->data << " -> ";
    inorder(node->right);
}

int main(){
    Node* root = NewNode('A');
    Node* nodeB = insert_left(root, 'B');
    Node* nodeC = insert_right(root, 'C');

    Node* nodeD = insert_left(nodeB, 'D');
    Node* nodeE = insert_right(nodeB, 'E');
    Node* nodeH = insert_left(nodeE, 'H');  
    Node* nodeJ = insert_left(nodeH, 'J');   

    Node* nodeF = insert_left(nodeC, 'F');
    Node* nodeG = insert_right(nodeC, 'G');
    Node* nodeI = insert_right(nodeF, 'I');
  

  cout << "Inorder traversal" << endl;
  inorder(root);
}