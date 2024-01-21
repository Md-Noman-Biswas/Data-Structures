#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    public:
    Node *head = NULL;

    public:
    void insert(int data){  //will insert at the end
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            return;
        }

        Node* temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }

    void print(Node *current){
        if(current == NULL) return;
        cout << current->data << " ";
        print(current->next);
    }
};


int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.print(list.head);
}