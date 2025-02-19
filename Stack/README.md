# Stack Implementation in C++

## Overview
This project provides a simple **Stack** implementation using an array in C++. It includes essential operations such as **push**, **pop**, **peek**, and **display**. The program demonstrates fundamental stack operations with proper error handling.

## Features
- **Push**: Add an element to the stack.
- **Pop**: Remove the top element from the stack.
- **Peek**: Retrieve the top element without removing it.
- **Check if Empty**: Verify if the stack has no elements.
- **Check if Full**: Detect when the stack reaches its maximum capacity.
- **Display**: Print all stack elements.

## Core Lines of Code
```cpp
class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(int value) {
        if (isFull()) return;
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) return;
        top--;
    }

    int peek() {
        return isEmpty() ? -1 : arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--)
            std::cout << arr[i] << " ";
    }
};
```

## Use Cases
- **Algorithm Design**: Stacks are fundamental in recursion, backtracking, and parsing.
- **Expression Evaluation**: Used in evaluating postfix/prefix expressions.
- **Undo/Redo Functionality**: Used in text editors and command history.
- **Function Call Management**: Used in system memory for managing function calls.

## How to Run
1. Copy the source code into a file (`Stack.cpp`).
2. Compile using:
   ```
   g++ -o stack Stack.cpp
   ```
3. Run the executable:
   ```
   ./stack
   ```

## Example Output
```
10 pushed to stack
20 pushed to stack
30 pushed to stack
Stack elements: 30 20 10
Top element: 30
30 popped from stack
Stack elements: 20 10
```
**asciinema**:https://asciinema.org/a/lzymDObvRAYm0z3csb7TplgSY
