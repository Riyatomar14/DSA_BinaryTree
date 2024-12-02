#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
   Node* root1 = NULL;
    cout << "Input for first tree:\n";
    takeInput(root1);

    Node* root2 = NULL;
    cout << "Input for second tree:\n";
    takeInput(root2);

    cout << "In-order traversal of the first tree: ";
    inorder(root1);
    cout << endl;

    cout << "Pre-order traversal of the first tree: ";
    preorder(root1);
    cout << endl;

    cout << "Post-order traversal of the first tree: ";
    postorder(root1);
    cout << endl;

    cout << "Height of the first tree: " << height(root1) << endl;

    cout << "Leaf nodes in the first tree: " << countLeafNodes(root1) << endl;
    cout << "Non-leaf nodes in the first tree: " << countNonLeafNodes(root1) << endl;

    if (areEqual(root1, root2)) {
        cout << "The two BSTs are equal.\n";
    } else {
        cout << "The two BSTs are not equal.\n";
    }

    cout << "Minimum value in the first tree: " << findMin(root1) << endl;
    cout << "Maximum value in the first tree: " << findMax(root1) << endl;


    int key = 5;
    cout << "Deleting " << key << " from the BST.\n";
    root = deleteNode(root, key);

    cout << "In-order traversal of the BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
