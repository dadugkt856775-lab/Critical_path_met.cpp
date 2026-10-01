#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void serialize(Node* root, stringstream& ss) {
    if (root == nullptr) {
        ss << "# ";
        return;
    }

    ss << root->data << " ";

    serialize(root->left, ss);
    serialize(root->right, ss);
}

Node* deserialize(stringstream& ss) {
    string value;
    ss >> value;

    if (value == "#")
        return nullptr;

    Node* root = new Node(stoi(value));

    root->left = deserialize(ss);
    root->right = deserialize(ss);

    return root;
}

void inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    stringstream ss;

    serialize(root, ss);

    cout << "Serialized Tree: " << ss.str() << endl;

    Node* newRoot = deserialize(ss);

    cout << "Deserialized Inorder: ";
    inorder(newRoot);

    return 0;
}
