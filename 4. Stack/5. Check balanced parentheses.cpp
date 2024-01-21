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

bool isBalanced(string s){
    Stack st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(st.isEmpty()){
                return false;
            }
            char top = st.top();
            st.pop();

            if ((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}


int main(){
    string s;
    cin >> s;
    if(isBalanced(s)){
        cout << "Balanced" << "\n";
    }else{
        cout << "Not Balanced" << "\n";
    }
}