#include <iostream>

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
    void insert(int x){
        Node* n = new Node();
        n->data = x;
        n->next = head;

        if(head == NULL){
            head = n;
            n->next = head;
        }else{
            Node* temp = head;
            while(temp->next != head){       
                temp = temp->next;    
            }
            temp->next = n;
        }
        
    }

    void insertAtHead(int x){
        Node *n = new Node();
        n->data = x;
        n->next = head;

        if(head == NULL){
            head = n;
            n->next = head; //making it circular
        }else{
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;//the last node points it back to the head
            }
            temp->next = n;
            head = n;
        }
    }

    void deleteAtHead(){
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }

        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;
        delete(toDelete);
    }

    void deletion(int n){
        if(n == 1){
            deleteAtHead();
            return;
        }
        Node* temp1 = head;
        for(int i=0; i<n-2; i++){
            temp1 = temp1->next;
        }
        
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
    }

    void print(){
        Node* current = head;           
        cout << "List is: ";
        while (current->next != head) {       
            cout << current->data << " ";  
            current = current->next;      
        }
        cout << current->data << "\n";
    }

};

int main(){
    LinkedList list;

    cout << "How many numbers: " << "\n";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter the Number: " << "\n";
        cin >> x;
        list.insert(x);
        list.print();
    }

    //cout << "Insert at head: " << "\n";
    list.print();
    //cout << "Deleted : " << "\n";
    list.deletion(3);
    list.print();
    //list.insertAtHead(y);
    //list.print();
}
