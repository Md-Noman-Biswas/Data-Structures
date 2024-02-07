#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		Node* current = Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}

// Function to Insert Node in a Binary Search Tree
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
	/*Code To Test the logic
	  Creating an example tree
	            7
			   / \
			  4   9
			 / \   
			1   6  
    */
	Node* root = NULL;
    root = Insert(root, 7); 
    root = Insert(root, 4);
    root = Insert(root, 9);
    root = Insert(root, 1);
    root = Insert(root, 6);

	//Print Nodes in Level Order. 
	LevelOrder(root);
    cout << "\n";

    cout << is_Binary_Search_Tree(root) << "\n";
}
