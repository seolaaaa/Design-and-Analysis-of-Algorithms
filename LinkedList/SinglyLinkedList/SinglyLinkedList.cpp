#include <iostream>
using namespace std;

struct Node {  // Node structure
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}  // Constructor
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}  // Initialize head to null

    ~SinglyLinkedList() {  // Destructor to free memory
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() { return head == nullptr; }  // Check if list is empty

    void insertAtBeginning(int val) {  // Insert at start
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {  // Insert at end
        Node* newNode = new Node(val);
        if (isEmpty()) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {  // Delete first node
        if (isEmpty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {  // Delete last node
        if (isEmpty()) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    bool search(int val) {  // Search for a value
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void reverse() {  // Reverse the list
        Node* prev = nullptr, * current = head, * next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void printList() {  // Print the list
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);  // Insert 10 at beginning
    list.insertAtBeginning(20);  // Insert 20 at beginning
    list.insertAtEnd(30);        // Insert 30 at end
    list.insertAtEnd(40);        // Insert 40 at end

    cout << "Original List: ";
    list.printList();

    cout << "After deleting from beginning: ";
    list.deleteAtBeginning();
    list.printList();

    cout << "After deleting from end: ";
    list.deleteAtEnd();
    list.printList();

    cout << "Search for 30: " << (list.search(30) ? "Found" : "Not Found") << endl;

    cout << "Reversed List: ";
    list.reverse();
    list.printList();

    return 0;
}
