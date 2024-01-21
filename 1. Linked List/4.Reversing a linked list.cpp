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
    
    void print(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverse() {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    
};


int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.reverse();
    list.print();

}