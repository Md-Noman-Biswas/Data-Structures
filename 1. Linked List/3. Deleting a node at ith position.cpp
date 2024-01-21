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

    void Delete(int n){
        Node* temp1 = head;
        if(n == 1){
            head = temp1->next;
            delete temp1;
            return;
        }
        for(int i=0; i<n-2; i++){
            temp1 = temp1->next;//points to n-1 th node
        }
        Node* temp2 = temp1->next;//nth Node, cause previously it was n-1 th
        temp1->next = temp2->next;//temp1 now points to n+1 th Node
        delete temp2;
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
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(5);
    list.print();
    int n;
    cin >> n;
    list.Delete(n);
    list.print();
}