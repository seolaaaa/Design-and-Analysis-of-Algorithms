#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() { head = nullptr; }

    // Insert at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (!head) {  // If list is empty
            head = newNode;
            head->next = head; // Circular reference
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to last node
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    // Delete a node by value
    void remove(int value) {
        if (!head) return;
        Node *current = head, *prev = nullptr;
        do {
            if (current->data == value) {
                if (prev) prev->next = current->next;
                else { // Deleting head
                    Node* temp = head;
                    while (temp->next != head) temp = temp->next;
                    head = head->next;
                    temp->next = head;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }

    // Display the list
    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Driver code
int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.display(); // Output: 10 20 30
    cll.remove(20);
    cll.display(); // Output: 10 30
    return 0;
}
