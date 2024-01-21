/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>

class Node{
    public:
	int data;
	Node* next;
}; 


class queue{
    // Two glboal variables to store address of front and rear nodes.
    public:
    Node* front = NULL;
    Node* rear = NULL;

    // To Enqueue an integer
    void Enqueue(int x){
        Node* temp = new Node();
        temp->data =x; 
        temp->next = NULL;
        if(front == NULL && rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    // To Dequeue an integer.
    void Dequeue(){
        struct Node* temp = front;
        if(front == NULL) {
            printf("Queue is Empty\n");
            return;
        }
        if(front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }
        free(temp);
    }

    int Front(){
        if(front == NULL) {
            printf("Queue is empty\n");
        }else return front->data;
    }

    void Print(){
        struct Node* temp = front;
        while(temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
    queue q;
	q.Enqueue(2); q.Print(); 
	q.Enqueue(4); q.Print();
	q.Enqueue(6); q.Print();
    q.Dequeue(); q.Print();
}
