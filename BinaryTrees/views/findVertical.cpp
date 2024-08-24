#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    vector<vector<int>> findVertical(Node* root){
        map<int, map<int, multiset<int>>> nodes;
        vector<vector<int>>ans;
        queue<pair<Node*,pair<int,int>>> todo;

        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            Node* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;

            nodes[x][y].insert(temp->data);
            if(temp->left){
                todo.push({temp->left,{x-1,y+1}});
            }if(temp->right){
                todo.push({temp->right,{x+1,y+1}});
            }
        }
        for(auto it:nodes){
            vector<int>col;
            for(auto c:it.second){
                col.insert(col.end(),c.second.begin(),c.second.end());
            }ans.push_back(col);
        }return ans;
    }
};
void printResult(const vector<vector<int>>& result) {
    for(auto level : result) {
        for(auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;
    vector<vector<int>> verticalTraversal = solution.findVertical(root);

    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);

    return 0;
}/*Time Complexity: O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.
Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. 
Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).
Space Complexity: O(N + N/2)--map o(o(n) and queue) */