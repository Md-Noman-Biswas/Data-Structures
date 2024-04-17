#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* NewNode(char data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert_left(Node* root, char data){
    root->left = NewNode(data);
    return root->left;
}

Node* insert_right(Node* root, char data){
    root->right = NewNode(data);
    return root->right;
}

void preorder(Node* root){
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        if(temp != NULL){
            cout << temp->data << " -> ";
            st.push(temp->right);
            st.push(temp->left);
        }
    }
}

void postorder(Node* root){
    stack<Node*> st;
    stack<char> output;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        if(temp != NULL){
            output.push(temp->data);
            st.push(temp->left);
            st.push(temp->right);
        }
    }

    while(!output.empty()){
        cout << output.top() << " -> ";
        output.pop();
    }
}

void inorder(Node* root){
    stack<Node*> st;
    Node* current = root;

    while(current != NULL || !st.empty()){
        while(current != NULL){
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data << " -> ";
        current = current->right;
    }
}


int main(){
    Node* root = NewNode('A');
    Node* nodeB = insert_left(root, 'B');
    Node* nodeC = insert_right(root, 'C');

    Node* nodeD = insert_left(nodeB, 'D');
    Node* nodeE = insert_right(nodeB, 'E');
    Node* nodeH = insert_left(nodeE, 'H');
    Node* nodeJ = insert_left(nodeH, 'J');

    Node* nodeF = insert_left(nodeC, 'F');
    Node* nodeG = insert_right(nodeC, 'G');
    Node* nodeI = insert_right(nodeF, 'I');

    cout << "Preorder traversal" << endl;
    preorder(root);
    
    cout << "\nInorder traversal" << endl;
    inorder(root);

    cout << "\nPostorder traversal" << endl;
    postorder(root);
}