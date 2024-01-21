#include <iostream>

using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Head of the linked list
Node* head = nullptr;

// Function to insert a new node at the end of the linked list
void insert(int x) {
    // Create a new node
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;

    // If the list is empty, make the new node the head
    if (head == nullptr) {
        head = temp;
    } else {
        // Traverse to the end of the list
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        // Insert the new node at the end
        last->next = temp;
    }
}

// Function to print the elements of the linked list
void print() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Insert data into the linked list
    insert(10);
    insert(20);
    insert(30);

    // Print the linked list
    print();

    // Insert more data
    insert(40);
    insert(50);

    // Print the updated linked list
    print();

    return 0;
}