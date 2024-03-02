// C++ Program of above implementation
#include <iostream>
using namespace std;

// Struct declaration
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// Node creation
struct Node* newNode(int data)
{
	struct Node* nn = new Node;
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

// Function to insert data in BST
struct Node* insert(struct Node* root, int data)
{
	if (root == NULL)
		return newNode(data);
	else {
		if (data < root->data)
			root->left = insert(root->left, data);
		if (data > root->data)
			root->right = insert(root->right, data);
		return root;
	}
}

// InOrder function to display value of array
// in sorted order
void inOrder(struct Node* root)
{
	if (root == NULL)
		return;
	else {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 3, 2, 5, 4, 4 };

	// Finding size of array arr[]
	int n = sizeof(arr) / sizeof(arr[0]);

	struct Node* root = NULL;

	for (int i = 0; i < n; i++) {

		// Insert element of arr[] in BST
		root = insert(root, arr[i]);
	}

	// Inorder Traversal to print nodes of Tree
	inOrder(root);
	return 0;
}
