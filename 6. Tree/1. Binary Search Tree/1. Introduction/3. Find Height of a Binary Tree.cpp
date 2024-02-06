#include<bits/stdc++.h>
using namespace std;

class BstNode{
public:
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

int findMin(BstNode* root){
    if(root == NULL){
        cout << "Error: Tree is Empty\n";
        return -1;
    }

    BstNode* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

int findMax(BstNode* root){
    if(root == NULL){
        cout << "Error: Tree is Empty\n";
        return -1;
    }

    BstNode* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}

//recursive method
int recursive_findMin(BstNode* root){
    if(root == NULL){
        cout << "Error: Tree is Empty\n";
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return recursive_findMin(root->left);
}

int recursive_findMax(BstNode* root){
    if(root == NULL){
        cout << "Error: Tree is Empty\n";
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return recursive_findMax(root->right);
}

int findHeight(BstNode* root){
    if(root == NULL) return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int main() {
    BstNode* root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 2);
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 8);
    root = Insert(root, 1);
    root = Insert(root, 9);

    cout << "Height of the tree: " << findHeight(root) << endl;

    return 0;
}
