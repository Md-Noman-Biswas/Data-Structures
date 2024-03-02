#include <bits/stdc++.h>
using namespace std;
const int N = 1001;

vector<int> heap(N);
int heapSize = 0;

void heap_push(int val){
    if(heapSize >= N){
        cout << "overflow" << "\n";
        return;
    }

    heap[heapSize] = val;//heap.push_back();
    int curr = heapSize;
    //can also use heapify up algorithm
    while(curr > 0 and heap[(curr - 1) / 2] < heap[curr]){
        swap(heap[(curr - 1) / 2], heap[curr]);
        curr = (curr - 1) / 2;
    }
    heapSize++;
}

int heap_pop(){
    if(heapSize <= 0){
        cout << "underflow" << "\n";
        return -1;
    }

    int popped = heap[0];
    int curr = 0;
    swap(heap[0], heap[heapSize - 1]);
    heapSize--;//heap.pop();

    //max_Heapify- can also use the heapify down algorithm
    while((2 * curr + 1) < heapSize){
        int child;
        if((2 * curr + 2) == heapSize){ // if only have left child
            child = 2 * curr + 1;
        }else{
            if(heap[2 * curr + 1] > heap[2 * curr + 2]){
                child = 2 * curr + 1;
            }else{
                child = 2 * curr + 2;
            }
        }

        if(heap[curr] < heap[child]){
            swap(heap[curr], heap[child]);
            curr = child;
        }else{
            break;
        }
    }
    return popped;
}

int main(){
    heap_push(2);
    heap_push(4);
    heap_push(1);
    heap_push(5);
    cout << "popped->" << heap_pop();
    cout << "\n";
    for(int i = 0; i < heapSize; i++){
        cout << heap[i] << " ";
    }
    cout << "\n";
}