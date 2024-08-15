#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMaxPathSum(Node* root, int &maxSum) {
    if (!root) return 0;
    int leftSum = max(0, findMaxPathSum(root->left, maxSum));
    int rightSum = max(0, findMaxPathSum(root->right, maxSum));
    maxSum = max(maxSum, leftSum + rightSum + root->data);
    return root->data + max(leftSum, rightSum);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    cout << "Maximum Path Sum: " << maxSum << endl;
    return 0;
}