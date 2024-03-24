#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};


Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}


int findDepth(Node* root, int x) {
    if (root == NULL)
        return -1;

    int dist = -1;

    if (root->data == x)
        return 0;  

    dist = findDepth(root->left, x);
    if (dist >= 0)
        return dist + 1;  

    dist = findDepth(root->right, x);
    if (dist >= 0)
        return dist + 1;  

    return dist;
}


int main()
{
	// Binary Tree Formation
	Node* root = newNode(5);
	root->left = newNode(10);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->left->right = newNode(25);
	root->left->right->right = newNode(45);
	root->right->left = newNode(30);
	root->right->right = newNode(35);

	int k = 45;

	// Function call to find the
	// depth of a given node
	cout << "Depth: "
		<< findDepth(root, k) << "\n";

	return 0;
}
