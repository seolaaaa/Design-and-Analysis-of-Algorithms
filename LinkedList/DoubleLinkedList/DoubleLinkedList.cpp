#include <iostream>
using namespace std;

// Doubly Linked List Class
class DoublyLinkedList {
private:
    struct Node {  // Node structure
        int data;
        Node *prev, *next;
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {} // Constructor

    // Insert at the beginning
    void insertBeginning(int val) { 
        Node* newNode = new Node(val);
        if (head) head->prev = newNode, newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode, newNode->prev = temp;
    }

    // Insert after a specific value
    void insertAfter(int afterVal, int newVal) {
        Node* temp = head;
        while (temp && temp->data != afterVal) temp = temp->next;
        if (!temp) { cout << "Value " << afterVal << " not found!\n"; return; }
        Node* newNode = new Node(newVal);
        newNode->next = temp->next, newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete a node
    void deleteNode(int val) {
        Node* temp = head;
        while (temp && temp->data != val) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        delete temp;
    }

    // Search for a value
    bool search(int val) {
        for (Node* temp = head; temp; temp = temp->next)
            if (temp->data == val) return true;
        return false;
    }

    // Reverse the linked list
    void reverse() {
        Node *temp = head, *prevNode = nullptr;
        while (temp) swap(temp->prev, temp->next), prevNode = temp, temp = temp->prev;
        if (prevNode) head = prevNode;
    }

    // Display the list
    void display() {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << " <-> ";
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);  // Insert elements
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    cout << "Original List: "; dll.display();

    dll.insertBeginning(5); // Insert at beginning
    cout << "After Inserting 5: "; dll.display();

    dll.insertAfter(20, 25); // Insert after 20
    cout << "After Inserting 25 after 20: "; dll.display();

    dll.deleteNode(20); // Delete node with value 20
    cout << "After Deleting 20: "; dll.display();

    cout << "Search for 25: " << (dll.search(25) ? "Found\n" : "Not Found\n");

    dll.reverse(); // Reverse the list
    cout << "Reversed List: "; dll.display();

    return 0;
}
