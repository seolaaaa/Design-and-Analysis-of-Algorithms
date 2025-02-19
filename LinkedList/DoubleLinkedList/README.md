# Doubly Linked List in C++

## Overview
This project is a simple implementation of a **Doubly Linked List** in C++. It includes essential operations such as insertion, deletion, searching, reversing, and printing the list. The program demonstrates dynamic memory allocation and pointer manipulation for efficient linked list operations.

## Features
- **Insert at Beginning**: Add a node to the start of the list.
- **Insert at End**: Add a node to the end of the list.
- **Insert After a Value**: Insert a new node after a specified value.
- **Delete a Node**: Remove a node by its value.
- **Search**: Check if a value exists in the list.
- **Reverse**: Reverse the order of nodes.
- **Print List**: Display all nodes in the list.

## Core Lines of Code
```cpp
struct Node {  // Defines the structure of a node
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertAtBeginning(int val) {  // Inserts a new node at the beginning
    Node* newNode = new Node(val);
    if (head) head->prev = newNode, newNode->next = head;
    head = newNode;
}

void deleteNode(int val) {  // Deletes a node with a given value
    Node* temp = head;
    while (temp && temp->data != val) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;
    delete temp;
}

void reverse() {  // Reverses the doubly linked list
    Node *temp = head, *prevNode = nullptr;
    while (temp) swap(temp->prev, temp->next), prevNode = temp, temp = temp->prev;
    if (prevNode) head = prevNode;
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
g++ -o doublylinkedlist DoubleLinkedList.cpp
```
3. Run the executable:
```
./doublylinkedlist
```
## Example Output
```
Original List: 10 <-> 20 <-> 30 <-> NULL
After inserting 5 at beginning: 5 <-> 10 <-> 20 <-> 30 <-> NULL
After inserting 25 after 20: 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> NULL
After deleting 20: 5 <-> 10 <-> 25 <-> 30 <-> NULL
Search for 25: Found
Reversed List: 30 <-> 25 <-> 10 <-> 5 <-> NULL
```
**asciinema**: https://asciinema.org/a/gSOn2KPgf3Rb6CSU7hG5siles 
