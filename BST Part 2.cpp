#include<iostream>
#include<queue>
#include<algorithm>  // for max function
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the tree recursively
Node* buildTree(Node*& root) {
    cout << "Enter the data to insert: ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;  
    }

    root = new Node(data);  

    cout << "Enter the data for inserting in left of: " << data << endl;
    root->left = buildTree(root->left); 

    cout << "Enter the data for inserting in right of: " << data << endl;
    root->right = buildTree(root->right);  // Recursively build the right subtree

    return root;  // Return the newly created node
}

// Function to print the tree in level-order (Breadth First Search)
void print(Node*& root) {
    if (root == NULL) {
        return;  // If tree is empty, nothing to print
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Marker to indicate end of level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;  // End of level
            if (!q.empty()) {
                q.push(NULL);  // Add marker for next level
            }
        } else {
            cout << temp->data << " ";  // Print node data
            if (temp->left) {
                q.push(temp->left);  // Add left child to the queue
            }
            if (temp->right) {
                q.push(temp->right);  // Add right child to the queue
            }
        }
    }
}

// Optimized height and balance check function
pair<int, bool> heightAndBalance(Node*& root) {
    if (root == NULL) {
        return {0, true};  // Height is 0, and the tree is balanced
    }

    // Recursively get height and balance status of left subtree
    auto left = heightAndBalance(root->left);

    // Recursively get height and balance status of right subtree
    auto right = heightAndBalance(root->right);

    // Current height is the maximum height of left and right subtrees + 1
    int height = max(left.first, right.first) + 1;

    // The tree is balanced if both left and right subtrees are balanced,
    // and the difference in height is <= 1
    bool balanced = left.second && right.second && abs(left.first - right.first) <= 1;

    return {height, balanced};
}

// Function to check if the tree is balanced
bool isBalanced(Node*& root) {
    return heightAndBalance(root).second;  // Return if the tree is balanced
}

// Function to search a node in the tree
bool search(Node*& root, int d) {
    if (root == NULL) {
        return false;  // If root is NULL, return false
    }
    if (root->data == d) {
        return true;  // If the data is found, return true
    }

    // Recursively search in left and right subtrees
    return search(root->left, d) || search(root->right, d);
}

int main() {
    Node* root = NULL;

    // Build the tree
    root = buildTree(root);

    // Print the tree
    cout << "Tree in level-order: " << endl;
    print(root);

    // Check if the tree is balanced
    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    // Search for a value in the tree
    int valueToSearch;
    cout << "Enter a value to search in the tree: ";
    cin >> valueToSearch;
    if (search(root, valueToSearch)) {
        cout << "Value " << valueToSearch << " found in the tree." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the tree." << endl;
    }

    return 0;
}
