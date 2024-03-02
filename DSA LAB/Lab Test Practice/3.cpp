#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* NewNode(int value){
    Node* temp = new Node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        root = NewNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    
    return root;
}

Node* find_min(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

int findMin(Node* root){
    Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

int findMax(Node* root){
    Node* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << "\n";
    inorder(root->right);
}

Node* Delete(Node* root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left != NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->right != NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }else{
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);
    
    Delete(root, 10);
    
    //cout << findMin(root) << "\n";
    inorder(root);
}