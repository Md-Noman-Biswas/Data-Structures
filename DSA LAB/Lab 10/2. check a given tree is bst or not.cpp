#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};


Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}


bool isBSTutil(Node* root, int minV, int maxV){
    if(root == NULL) return true;
    if((root->data > minV && root->data < maxV) && isBSTutil(root->left, minV, root->data) && isBSTutil(root->right, root->data, maxV)){
        return true;
    }else{
        return false;
    }
}


bool is_Binary_Search_Tree(Node* root){
    return isBSTutil(root, INT_MIN, INT_MAX);
}


int main() {
	Node* root = NULL;
    root = Insert(root, 7); 
    root = Insert(root, 4);
    root = Insert(root, 9);
    root = Insert(root, 1);
    root = Insert(root, 6);

    cout << is_Binary_Search_Tree(root) << "\n";
}
