#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insert(Node* head, int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

void print(Node *head){
    //this head is local variable to print. so it doesn't modify the orginal head
    cout << "List is: ";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main(){
    Node* head = NULL; //empty list
    cout << "How many numbers: " << "\n";
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cout << "Enter the Number: " << "\n";
        cin >> x;
        head = insert(head, x);
        print(head); 
    }
}