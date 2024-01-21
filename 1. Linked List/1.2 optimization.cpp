#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insert(Node** head, int x){//this head is a pointer to the pointer variable head, we could have named it anything
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(*head != NULL) temp->next = *head;
    *head = temp;
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
    Node* head;
    head = NULL; //empty list
    cout << "How many numbers: " << "\n";
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cout << "Enter the Number: " << "\n";
        cin >> x;
        insert(&head, x);
        print(head); 
    }
}