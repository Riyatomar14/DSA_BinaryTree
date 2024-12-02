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
    }
    else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node*& root) {
    int n, data;
    cout << "Enter the number of nodes to insert: ";
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> data;
        root = insertIntoBST(root, data);
    }
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int height(Node* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

bool areEqual(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    if (root1->data != root2->data) return false;
    return areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "The tree is empty." << endl;
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) {
        cout << "The tree is empty." << endl;
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
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

    return 0;
}
