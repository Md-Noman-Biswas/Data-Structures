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

void InorderTraversal(BstNode* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    InorderTraversal(root->left);

    // Visit the current node
    cout << root->data << " ";

    // Traverse the right subtree
    InorderTraversal(root->right);
}

int main() {
    BstNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 15);
    root = Insert(root, 5);
    root = Insert(root, 35);
    root = Insert(root, 50);
    root = Insert(root, 45);

    int min_element = findMin(root);
    cout << "Minimum Element: " << min_element << "\n";
    
    int max_element = findMax(root);
    cout << "Maximum Element: " << max_element << "\n";
    
    cout << "Inorder Traversal: ";
    InorderTraversal(root);
    cout << "\n";

    return 0;
}
