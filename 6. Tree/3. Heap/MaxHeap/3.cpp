#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            cerr << "Heap is empty.\n";
            return -1;
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    void deleteElement(int value) {
        auto it = find(heap.begin(), heap.end(), value);
        if (it != heap.end()) {
            int index = it - heap.begin();
            heap[index] = heap.back();
            heap.pop_back();
            heapifyDown(index);
        } else {
            cout << "Element not found in the heap.\n";
        }
    }


    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    //recursive
    /*
    void heapifyUp(int index) {
        if (index <= 0) {
            return;
        }

        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    */

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }


    /*
    //recursive
    void heapifyDown(int index) {
        int size = heap.size();
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    */

    // void heapify(int index) {
    //     heapifyUp(index);
    //     heapifyDown(index);
    // }

    void print() {
        while (!heap.empty()) {
            cout << extractMax() << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap;
    
    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(3);
    maxHeap.insert(7);
    maxHeap.deleteElement(10);

    cout << "MaxHeap: ";
    cout << "\n";
    maxHeap.print();
}
