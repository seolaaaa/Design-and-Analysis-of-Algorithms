# Circular Linked List in C++

## Overview
This project implements a **Circular Linked List** in C++. It supports insertion and displaying of elements while demonstrating dynamic memory allocation and pointer manipulation.

## Features
- **Insert at End**: Adds a new node at the end while maintaining circularity.
- **Delete a Node**: Removes a node by value while keeping the list properly linked.
- **Display the Lis**t: Prints all elements in a circular format.
- **Handles Edge Cases**: Supports operations on empty lists and deletion of the head node.
- **Efficient Memory Management**: Implements a destructor to prevent memory leaks.

## Core Lines of Code
```cpp
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() { head = nullptr; }

    void insert(int value) {  // Inserts a new node at the end
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(int value) {  // Deletes a node with the given value
        if (head == nullptr) return;

        Node *temp = head, *prev = nullptr;

        if (head->data == value && head->next == head) {  // If head is the only node
            delete head;
            head = nullptr;
            return;
        }

        do {  // Find the node to delete
            if (temp->data == value) break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data == value) {  // If node is found
            if (temp == head) {
                Node* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        }
    }

    void display() {  // Displays the circular linked list
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }

    ~CircularLinkedList() {  // Destructor to prevent memory leaks
        if (!head) return;
        Node *temp = head, *nextNode;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
        head = nullptr;
    }
};

```

## Use Cases
- **Basic Data Structure Learning**: Understand circular linked list operations.
- **Memory-Efficient Data Management**: Useful in scenarios requiring circular iteration.
- **Operating Systems & Scheduling**: Applied in round-robin scheduling.

## How to Run
1. Copy the source code into a `.cpp` file.
2. Compile using a C++ compiler:
   ```sh
   g++ -o circularlinkedlist CircularLinkedList.cpp
   ```
3. Run the executable:
   ```sh
   ./circularlinkedlist
   ```

## Example Output
```
Circular Linked List: 10 -> 20 -> 30 -> 40 -> (head)
After deleting 20: 10 -> 30 -> 40 -> (head)
```
**asciinema**: https://asciinema.org/a/iC4Q4dJOcJli7PbD4DUI7thfJ
