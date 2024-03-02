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

BstNode* Insert(BstNode* root, int data) {
	if(root == NULL) {
		root = GetNewNode(data);
	}
	
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	
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


int main(){
    BstNode* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 30);

    int min_element = findMin(root);
    cout << min_element << "\n";
    cout << findMax(root) << "\n";
    cout << "\n";

}