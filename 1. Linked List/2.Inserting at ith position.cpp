#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head = NULL;

public:
    void insert(int data, int n){
        Node* temp1 = new Node();
        temp1->data = data;
        temp1->next = NULL;
        if(n == 1){
            temp1->next = head;
            head = temp1;
            return;
        }
        Node* temp2 = head;
        for(int i=0; i<n-2; i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }


};

int main(){
    LinkedList list;
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 1);
    list.print();
    list.insert(5, 2);
    list.print();
}