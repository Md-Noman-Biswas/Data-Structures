#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;

void insert(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print(){
    Node* temp = head;
    cout << "List is: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main(){
    head = NULL; //empty list
    cout << "How many numbers: " << "\n";
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cout << "Enter the Number: " << "\n";
        cin >> x;
        insert(x);
        print(); 
    }
}