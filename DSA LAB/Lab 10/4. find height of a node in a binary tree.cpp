// C++ Program to solve the above problem
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};


Node* newNode(int item){
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void findDepthAndHeight(Node* root, int k){
	if(root == NULL) return;
	int depth = -1;
	int height = -1;
	queue<Node*> q;
	q.push(root);
	int level = 0;
	while(!q.empty()){
		int n = q.size();
		for(int i = 0; i<n; i++){
			Node* frontNode = q.front();
			q.pop();
			if(frontNode->data == k) depth = level;
			if(frontNode->left) q.push(frontNode->left);
			if(frontNode->right) q.push(frontNode->right);
		}
		level++;
	}
	height = level - depth - 1;
	cout<<"Depth : "<<depth<<endl;
	cout<<"Height : "<<height<<endl;
}

int main(){
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
	
	findDepthAndHeight(root, k);
	return 0;
}
