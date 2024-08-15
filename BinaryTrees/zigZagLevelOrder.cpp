#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    vector<vector<int>> zigZagLevelOrder(Node* root){
        queue<Node*>nodesQueue;
        vector<vector<int>>result;
        if(root==nullptr) return result;

        nodesQueue.push(root);
        bool leftToRight=true;

        while(!nodesQueue.empty()){
            int size=nodesQueue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                Node* node=nodesQueue.front();
                nodesQueue.pop();

                int index=leftToRight?i:(size-i-1);
                row[index]=node->data;

                if(node->left){
                    nodesQueue.push(node->left);
                }if(node->right){
                    nodesQueue.push(node->right);
                }
            }leftToRight=!leftToRight;
            result.push_back(row);
        }return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;
    vector<vector<int>> result = solution.zigZagLevelOrder(root);
    printResult(result);

    return 0;
}//Time Complexity: O(N) 
//where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and 
//dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time 
//operations which contributes to the overall linear time complexity.
//Space Complexity: O(N)