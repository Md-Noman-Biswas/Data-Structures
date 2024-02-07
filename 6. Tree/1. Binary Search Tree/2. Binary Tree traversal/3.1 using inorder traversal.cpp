#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

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

void InorderTraversal(Node* root, vector<int>& values) {
    if (root == NULL) return;

    InorderTraversal(root->left, values);
    values.push_back(root->data);
    InorderTraversal(root->right, values);
}

bool is_Binary_Search_Tree(Node* root) {
    vector<int> values;
    InorderTraversal(root, values);

    // Check if the values are in ascending order
    for (int i = 1; i < values.size(); i++) {
        if (values[i] <= values[i - 1]) {
            return false;
        }
    }
    return true;
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

    cout << is_Binary_Search_Tree(root) << "\n";


}
