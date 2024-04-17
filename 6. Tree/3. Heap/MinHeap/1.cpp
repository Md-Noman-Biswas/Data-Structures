#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }

        int minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minElement;
    }

    void deleteElement(int value) {
        auto it = find(heap.begin(), heap.end(), value);
        if (it != heap.end()) {
            int index = it - heap.begin();
            heap[index] = heap.back();
            heap.pop_back();
            heapifyDown(index);
        } else {
            cerr << "Element not found in the heap.\n";
        }
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Function to perform heapify-down operation
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

    void heapify(int index) {
        heapifyUp(index);
        heapifyDown(index);
    }

    // Function to print the elements of the heap using inorder-like traversal
    void printInorderTraversal() {
        cout << "Inorder Traversal: ";
        while (!heap.empty()) {
            cout << extractMin() << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;

    // Insert elements into the heap
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(3);
    minHeap.insert(7);

    // Print the initial heap
    cout << "Initial Heap: ";
    minHeap.printInorderTraversal();

    return 0;
}
