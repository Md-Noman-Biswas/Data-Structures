#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque{
private:
    Node* front = nullptr;
    Node* rear = nullptr;

public:
    void push_front(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = front;
        temp->prev = nullptr;
        if (front != nullptr){
            front->prev = temp;
        }
        if (front == nullptr){
            rear = temp;
        }
        front = temp;
    }

    void push_back(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;
        temp->prev = rear;
        if (front == nullptr && rear == nullptr){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void pop_front(){
        if (front == nullptr){
            cout << "Deque is Empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr){
            front->prev = nullptr;
        }
        delete temp;
        if (front == nullptr){
            rear = nullptr;
        }
    }

    void pop_back(){
        if (front == nullptr){
            cout << "Deque is Empty" << endl;
            return;
        }
        if (front == rear){
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
        if (front == nullptr){
            cout << "Deque is empty" << endl;
            return -1; 
        }
        return front->data;
    }

    int back_value(){
        if (rear == nullptr){
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
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Deque myDeque;

    myDeque.push_back(10);
    myDeque.push_front(5);
    myDeque.push_back(20);
    myDeque.print();
    cout << "Front: " << myDeque.front_value() << endl;
    cout << "Back: " << myDeque.back_value() << endl;

    myDeque.pop_front();
    myDeque.pop_back();

    myDeque.print();

    return 0;
}
