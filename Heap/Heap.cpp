#include <iostream>
using namespace std;

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

    bool isEmpty() { return heapSize == 0; }

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
        if (isEmpty()) {
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

int main() {
    MinHeap heap(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);

    cout << "Heap elements: ";
    heap.display();

    cout << "Extracted Min: " << heap.extractMin() << endl;
    cout << "Heap after extraction: ";
    heap.display();

    return 0;
}
