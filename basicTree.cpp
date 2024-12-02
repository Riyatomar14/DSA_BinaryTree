#include <iostream>
#include <queue>
using namespace std;

// Class definition for a node
class node {
public:
    int data;
    node* left;
    node* right;

    // Constructor
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the binary tree
node* buildTree(node* root) {
    cout << "Enter the value of the data (-1 for NULL): ";
    int data;
    cin >> data;

    // Base case for recursion
    if (data == -1) {
        return NULL;
    }

    // Create a new node
    root = new node(data);

    cout << "Enter the value of the left child of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter the value of the right child of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

// Function for level order traversal
void LevelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL); // Marker for level separation

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl; // End of a level
            if (!q.empty()) {
                q.push(NULL); // Add marker for the next level
            }
        } else {
            cout << temp->data << " ";

            // Enqueue left child first for left-to-right traversal
            if (temp->left) {
                q.push(temp->left);
            }

            // Enqueue right child
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Main function
int main() {
    node* root = NULL;

    // Build the binary tree
    root = buildTree(root);

    // Perform level order traversal
    cout << "Level Order Traversal of the binary tree:" << endl;
    LevelOrderTraversal(root);

    return 0;
}
