#include<iostream>
#include<string.h>
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


void Reverse(char *c, int n){
    Stack st;
    for(int i=0; i<n; i++){
        st.push(c[i]);
    }

    for(int i=0; i<n; i++){
        c[i] = st.top();
        st.pop();
    }
}

int main(){
    char c[51];
    printf("Enter a string\n");
    gets(c);
    Reverse(c, strlen(c));
    cout << c << "\n";
}