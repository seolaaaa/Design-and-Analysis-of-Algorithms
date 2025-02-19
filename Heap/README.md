# Min Heap in C++

## Overview
This project implements a **Min Heap** data structure in C++. It supports insertion, extraction of the minimum element, and displaying the heap elements while maintaining the heap property.

## Features
- **Insertion**: Adds a new element while preserving the min heap property.
- **Extract Minimum**: Removes and returns the smallest element in the heap.
- **Heapify Operations**: Uses heapify-up and heapify-down for maintaining heap order.
- **Dynamic Array Allocation**: The heap uses a dynamically allocated array.
- **Error Handling**: Detects and handles heap overflow and underflow conditions.

## Core Lines of Code
```cpp
class MinHeap {
private:
    int* heapArray;
    int capacity;
    int heapSize;

    void heapifyDown(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heapArray[left] < heapArray[smallest])
            smallest = left;
        if (right < heapSize && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heapArray[i], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && heapArray[parent] > heapArray[i]) {
            swap(heapArray[i], heapArray[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

public:
    MinHeap(int cap) {
        heapSize = 0;
        capacity = cap;
        heapArray = new int[cap];
    }

    ~MinHeap() { delete[] heapArray; }

    void insert(int value) {
        if (heapSize == capacity) {
            cout << "Heap Overflow\n";
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        heapArray[i] = value;
        heapifyUp(i);
    }

    int extractMin() {
        if (heapSize == 0) {
            cout << "Heap Underflow\n";
            return -1;
        }
        int root = heapArray[0];
        heapArray[0] = heapArray[heapSize - 1];
        heapSize--;
        heapifyDown(0);
        return root;
    }

    void display() {
        for (int i = 0; i < heapSize; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }
};
```
## Use Cases
- **Priority Queues**: Useful for implementing priority-based scheduling.
- **Graph Algorithms**: Used in Dijkstra’s and Prim’s algorithms.
- **Sorting**: Can be used to implement Heap Sort efficiently.
- **Memory Management**: Helps in efficient memory allocation strategies.

## How to Run
1. Copy the source code into a .cpp file.
2. Compile using a C++ compiler:
   ```
   g++ -o heap Heap.cpp
   ```
3. Compile using a C++ compiler:
    ```
   ./heap
   ```
## Example Output
 ```
Heap elements: 1 3 8 5
Extracted Min: 1
Heap after extraction: 3 5 8
 ```
**asciinema**:https://asciinema.org/a/yWCRcPItaP24of0rEitTzMiO8
