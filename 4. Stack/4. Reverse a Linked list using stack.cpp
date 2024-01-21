#include<iostream>
#include<string.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    Node* head = NULL;

public:
    void insert(int x){
        Node* temp = new Node();  // Creates a new box (node) called temp.
        temp->data = x;           // Puts the number x into the new box.
        temp->next = head;         // Makes the new box point to whatever the head is pointing to.
        head = temp;               // Now, updates the head to point to the new box.
    }
 

    void print(){
        Node* current = head;           // Start from the first box (node).
        cout << "List is: ";
        while (current != NULL) {       // As long as there is a box (node) to look at:
            cout << current->data << " ";  // Print the number in the current box.
            current = current->next;       // Move to the next box in the row.
        }
        cout << "\n";
    }

};

class Stack{
    private:
    Node* Top = NULL;

    public:
    void push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = Top;
        Top = temp;
    }

    void pop(){
        Node* temp;
        if(Top == NULL){
            return;
        }
        temp = Top;
        Top = Top->next;
        free(temp);
    }

    int top(){
        return Top->data;
    }

    bool isEmpty(){
        if(Top == NULL){
            return true;
        }else{
            return false;
        }
    }

    void print(){
        Node* current = Top;
        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};



void Reverse(Node* head){
    Stack st;
    Node* current = head;

    while(current != NULL){
        st.push(current->data);
        current = current->next;
    }

    current = head;
    while(current != NULL){
        current->data = st.top();
        st.pop();
        current = current->next;
    }
}

int main(){
    LinkedList list;
    list.insert(0);
    list.insert(3);
    list.insert(4);
    list.print();

    Reverse(list.head);

    list.print();
    
}