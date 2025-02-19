#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = nullptr; }

    // Insert a node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Inorder traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Preorder traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Postorder traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    // Search for a value in the tree
    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    bool search(int key) {
        return search(root, key);
    }
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

    cout << "Inorder traversal: ";
    tree.inorder();
    
    cout << "Preorder traversal: ";
    tree.preorder();
    
    cout << "Postorder traversal: ";
    tree.postorder();
    
    int key = 40;
    if (tree.search(key))
        cout << key << " found in the tree." << endl;
    else
        cout << key << " not found in the tree." << endl;
    
    return 0;
}
