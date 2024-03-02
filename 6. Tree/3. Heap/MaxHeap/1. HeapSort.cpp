#include <bits/stdc++.h>
using namespace std;


void heapify_down(vector<int> &heap, int curr, int size){
    int l = 2 * curr + 1;
    int r = 2 * curr + 2;
    int largest = curr;
    if(l < size && heap[l] > heap[largest]){
        largest = l;
    }

    if(r < size && heap[r] > heap[largest]){
        largest = r;
    }

    if(largest != curr){
        swap(heap[curr], heap[largest]);
        heapify_down(heap, largest, size);
    }
}

void heapSort(vector<int> &heap){
    //build heap
    for(int i = heap.size() / 2 - 1; i >= 0; i--){
        heapify_down(heap, i, heap.size());
    }

    for(int i = heap.size() - 1; i >= 0; i--){
        swap(heap[0], heap[i]);
        heapify_down(heap, 0, i);
    }
}


int main(){
    vector<int> heap = {9, 6, 8, 2, 1, 4, 5};
    heapSort(heap);

    for(auto it: heap){
        cout << it << " ";
    }
    cout << "\n";
}