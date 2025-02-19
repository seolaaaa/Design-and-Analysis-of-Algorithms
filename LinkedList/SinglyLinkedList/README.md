# Singly Linked List in C++

## Overview
This project is a simple implementation of a **Singly Linked List** in C++. It includes essential operations such as insertion, deletion, searching, reversing, and printing the list. The program demonstrates dynamic memory allocation and pointer manipulation for efficient linked list operations.

## Features
- **Insert at Beginning**: Add a node to the start of the list.
- **Insert at End**: Add a node to the end of the list.
- **Delete from Beginning**: Remove the first node.
- **Delete from End**: Remove the last node.
- **Search**: Check if a value exists in the list.
- **Reverse**: Reverse the order of nodes.
- **Print List**: Display all nodes in the list.

## Core Lines of Code
```cpp
struct Node {  // Defines the structure of a node
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtBeginning(int val) {  // Inserts a new node at the beginning
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void deleteAtEnd() {  // Deletes the last node
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void reverse() {  // Reverses the linked list
    Node *prev = nullptr, *current = head, *next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
```
## Use Cases
- **Basic Data Structure Learning**: Helps understand linked list operations.
- **Competitive Programming**: Useful for solving linked list-based problems.
- **Memory Management Practice**: Demonstrates dynamic memory allocation in C++.
- **Building Larger Applications**: Forms the basis for more complex data structures like stacks, queues, and graphs.

## How to Run

1. Copy the source code into a .cpp file.

2. Compile using a C++ compiler:
```
g++ -o singlylinkedlist SinglyLinkedList.cpp
```
3. Run the executable:
   ```
   ./singlylinkedlist
   ```
## Example Ouput
```
Original List: 20 -> 10 -> 30 -> 40 -> NULL
After deleting from beginning: 10 -> 30 -> 40 -> NULL
After deleting from end: 10 -> 30 -> NULL
Search for 30: Found
Reversed List: 30 -> 10 -> NULL
```
