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
        Node* temp = new Node();  // Creates a new box (node) called temp.
        temp->data = x;           // Puts the number x into the new box.
        temp->next = head;         // Makes the new box point to whatever the head is pointing to.
        head = temp;               // Now, updates the head to point to the new box.
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
}
