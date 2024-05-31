#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
    public:

    vector<int> bfsOfGraph (int v, vector<int>adj[]){
        int vis[v]={0};
        vis[0]=1;
        queue<int> q;
        vector<int>bfs;
        //this is to push the initial node of the array
        q.push(0);
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            bfs.push_back(Node);
            for(auto it: adj[Node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return bfs;
    }
};

void addEdge(vector<int>adj[],int v, int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printAns(vector<int>adj){
    for(int i=0;i<adj.size();i++){
        cout<< adj[i]<<" ";
    }
}

int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}