# Array Queue Implementation in C++

## Overview
This project implements a **Queue** using a **fixed-size array** in C++. It supports fundamental queue operations like **enqueue, dequeue, peek, and display**. The queue follows the **FIFO (First-In, First-Out)** principle, ensuring that elements are processed in the order they are inserted.

## Features
- **Enqueue** – Adds an element to the rear of the queue.
- **Dequeue** – Removes an element from the front of the queue.
- **Peek** – Retrieves the front element without removing it.
- **Check if Full/Empty** – Prevents overflow and underflow errors.
- **Display Queue** – Prints all elements in order.
- **Efficient Operations** – Uses constant-time operations **O(1)** for enqueue and dequeue.

## Core Lines of Code
```cpp
#include <iostream>
#define MAX 100  // Maximum queue size

class ArrayQueue {
private:
    int arr[MAX];
    int front, rear;

public:
    ArrayQueue() { front = -1; rear = -1; }

    bool isFull() { return rear == MAX - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    ArrayQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
```

## Use Cases
- **Task Scheduling** – Manages processes in operating systems.
- **Print Queue Management** – Orders print jobs efficiently.
- **Customer Service Systems** – Helps implement ticketing systems.
- **Buffer Management** – Handles data streams in networking.

## How to Run
1. Copy the source code into a `.cpp` file (e.g., `ArrayQueue.cpp`).
2. Compile the code using a C++ compiler:
   ```sh
   g++ -o queue Queue.cpp
   ```
3. Run the program:
   ```sh
   ./queue
   ```

## Example Output
```
10 20 30  
20 30  
```
**asciinema**:https://asciinema.org/a/KyxOFGm0VcLVBtRcFxQE9AihX


