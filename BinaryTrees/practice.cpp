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
        queue<pair<Node*,pair<int,int>>> todo;

        
    }
};