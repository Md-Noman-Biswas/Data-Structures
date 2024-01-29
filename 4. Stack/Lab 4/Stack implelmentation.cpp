#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class Stack{
    private:
    Node* Top = NULL;

    public:
    void push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = Top;
        Top = temp;
    }

    void pop(){
        Node* temp;
        if(Top == NULL){
            return;
        }
        temp = Top;
        Top = Top->next;
        free(temp);
    }

    int top(){
        return Top->data;
    }

    bool isEmpty(){
        if(Top == NULL){
            return true;
        }else{
            return false;
        }
    }

    void print(){
        Node* current = Top;
        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main(){
    Stack st;

    st.push(1);
    st.push(3);
    st.push(4);
    st.print();
    st.pop();
    if(!st.isEmpty()){
        cout << "Not Empty" << "\n";
    }else{
        cout << "Empty" << "\n";
    }
    st.print();
    
}
