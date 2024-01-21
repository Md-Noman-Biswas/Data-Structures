#include<iostream>
using namespace std;

#define MAX_SIZE 101

int arr[MAX_SIZE];
int Top = -1;

void push(int x){
    if(Top == MAX_SIZE - 1){
        cout << "Error: stack overflow" << "\n";
        return;
    }
    Top++;
    arr[Top] = x;
}

void pop(){
    if(Top == -1){
        cout << "Error: stack underflow" << "\n";
        return;
    }
    Top--;
}

int top(){
    return arr[Top];
}

void print(){
    int i;
    cout << "Stack: ";
    for(int i=0; i<=Top; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}


int main(){
    push(2);
    print();
    push(5);
    print();
    push(10);
    print();
    pop();
    print();
}