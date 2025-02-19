#include <iostream>
#define MAX 100  // Maximum stack size

class Stack {
private:
    int arr[MAX]; // Array to store stack elements
    int top;      // Index of the top element

public:
    Stack() { top = -1; }  // Constructor initializes stack as empty

    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow: Cannot push " << value << "\n";
            return;
        }
        arr[++top] = value;
        std::cout << value << " pushed to stack\n";
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow: No elements to pop\n";
            return;
        }
        std::cout << arr[top--] << " popped from stack\n";
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is Empty\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    
    std::cout << "Top element: " << s.peek() << "\n";
    
    s.pop();
    s.display();

    return 0;
}
