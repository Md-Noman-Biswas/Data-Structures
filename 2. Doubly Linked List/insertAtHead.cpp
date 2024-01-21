#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

class Linked_List{
    private:
    Node* head = NULL;

    public:
    void insertAtHead(int x){
        Node* newNode = new Node();
        newNode->data = x;
        if(head == NULL){
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void reversePrint(){
        Node* temp = head;
        if(temp == NULL) return;
        while(temp->next != NULL){
            temp = temp->next;
        }
        cout << "Reverse: " << "\n";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->prev;
        } 
        cout << "\n";
    }

};

int main(){
    Linked_List list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.print();
    list.reversePrint();
}