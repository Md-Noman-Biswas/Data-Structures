#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
private:
    Node* head = NULL;

public:
    void insert(int data){
        Node* temp = new Node();
        temp->data = data;
        temp->next = nullptr;

        if (head == nullptr){
            head = temp;
            return;
        }

        Node* temp2 = head;
        while (temp2->next != nullptr){
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }

    void Delete(int n){
        Node* temp1 = head;
        if (n == 1){
            head = temp1->next;
            delete temp1;
            return;
        }
        for (int i = 0; i < n - 2; i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }

    void print(){
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

class Stack{
private:
    Node* top = NULL;

public:
    void push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop(){
        Node* temp;
        if (top == nullptr){
            return;
        }
        temp = top;
        top = top->next;
        free(temp);
    }

    int top_value(){
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    void print(){
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

class Deque{
private:
    Node* front = NULL;
    Node* rear = NULL;

public:

    void push_front(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = front;
        temp->prev = nullptr;
        if (front != nullptr) {
            front->prev = temp;
        }
        if (front == nullptr) {
            rear = temp;
        }
        front = temp;
    }

    void push_back(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;
        temp->prev = rear;
        if (front == nullptr && rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void pop_front(){
        if (front == nullptr) {
            cout << "Deque is Empty" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void pop_back(){
        if (front == nullptr) {
            cout << "Deque is Empty" << endl;
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        rear->next = nullptr;
        delete temp;
    }

    int front_value(){
        if (front == nullptr) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int back_value(){
        if (rear == nullptr) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return rear->data;
    }

    bool empty(){
        return front == nullptr;
    }

    void print(){
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(5);
    list.print();
    cout << "Enter the position you want to delete: " << endl;
    int n;
    cin >> n;
    list.Delete(n);
    list.print();

    
    Stack st;
    st.push(1);
    st.push(3);
    st.push(4);
    st.print();
    cout << "popped an element in stack" << endl;
    st.pop();
    cout << "checking if stack is empty...." << endl;
    if (!st.isEmpty()) {
        cout << "Not Empty" << endl;
    } else {
        cout << "Empty" << endl;
    }
    cout << "current stack elements" << endl;
    st.print();

    
    Deque myDeque;
    myDeque.push_back(10);
    myDeque.push_front(5);
    myDeque.push_back(20);
    cout << "Element in deque" << endl;
    myDeque.print();
    cout << "Front: " << myDeque.front_value() << endl;
    cout << "Back: " << myDeque.back_value() << endl;
    myDeque.pop_front();
    myDeque.pop_back();
    cout << "Element after popping from front and back" << endl;
    myDeque.print();

    return 0;
}
