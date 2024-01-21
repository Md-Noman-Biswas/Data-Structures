#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class Linked_List{
    private:
    Node* head = NULL;

    public:
    void insert(int x) {
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

    void print() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main() {
    Linked_List list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.print();
    list.insert(40);
    list.insert(50);
    list.print();
}