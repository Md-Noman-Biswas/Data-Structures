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
    //insert at head
    void insert(int x){
        Node* temp = new Node();  // Creates a new box (node) called temp.
        temp->data = x;           // Puts the number x into the new box.
        temp->next = head;         // Makes the new box point to whatever the head is pointing to.
        head = temp;               // Now, updates the head to point to the new box.
    }

    //insert at ith position
    void insert_at_n(int data, int n){
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

    //insert at end
    void insert_at_end(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
    } else {
        Node* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = temp;
        }
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

    // Delete at head
    void deleteAtHead() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;      // Point to the head node.
        head = head->next;      // Move the head to the next node.
        delete temp;            // Delete the original head node.

        cout << "Deleted at head. ";
                    // Print the updated list.
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Traverse to the last node and keep track of the previous node
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == nullptr) {
            // If there is only one node in the list
            head = nullptr;
        } else {
            // Update the previous node to remove the last node
            prev->next = nullptr;
        }

        delete temp;
        cout << "Deleted at end. ";
        print();  // Print the updated list.
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
    list.deleteAtEnd();
    list.deleteAtHead();
    list.print();
}