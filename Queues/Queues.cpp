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
