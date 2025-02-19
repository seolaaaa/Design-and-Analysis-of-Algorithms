# Binary Tree in C++

## **Overview**
This project implements a **Binary Tree** in C++ with fundamental operations such as:
- Insertion of nodes
- In-order, Pre-order, and Post-order traversal
- Searching for a value in the tree

## **Features**
- **Insert (`insert`)**: Adds a new node to the tree.
- **Traversal**:
  - **In-order (LNR)**: Left → Root → Right
  - **Pre-order (NLR)**: Root → Left → Right
  - **Post-order (LRN)**: Left → Right → Root
- **Search (`search`)**: Checks if a given value exists in the tree.

## **Core Code**
```cpp
#include <iostream>
using namespace std;

struct Node {  // Defines a tree node
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void inorder(Node* node) {  // In-order traversal (LNR)
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {  // Pre-order traversal (NLR)
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {  // Post-order traversal (LRN)
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    Node* insert(Node* node, int val) {  // Inserts a new node
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int key) {  // Searches for a value
        if (!node) return false;
        if (node->data == key) return true;
        return key < node->data ? search(node->left, key) : search(node->right, key);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) { root = insert(root, val); }
    bool search(int key) { return search(root, key); }
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.inorder();

    cout << "Pre-order Traversal: ";
    tree.preorder();

    cout << "Post-order Traversal: ";
    tree.postorder();

    cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    return 0;
}
```

## **Use Cases**
- **Data Storage and Retrieval**: Efficient searching and sorting.
- **Expression Trees**: Used in compilers and calculators.
- **Hierarchical Data Representation**: Useful for file systems, databases, and AI decision trees.

## **How to Run**
1. Copy the source code into a `.cpp` file, e.g., `binarytree.cpp`.
2. Compile using a C++ compiler:
   ```
   g++ -o binarytree BinaryTree.cpp
   ```
3. Run the executable:
   ```
   ./binarytree
   ```

## **Example Output**
```
Inorder traversal: 20 30 40 50 60 70 80
Preorder traversal: 50 30 20 40 70 60 80
Postorder traversal: 20 40 30 60 80 70 50
40 found in the tree.
```
**asciinema**:https://asciinema.org/a/meKyexOM6Tqz1QhRtkbmKwilA 
