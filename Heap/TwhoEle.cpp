#include <bits/stdc++.h>
using namespace std;

int main() {
vector<int> v={1,2,3} ;//{6,4,8};

priority_queue<int,vector<int>,greater<int>> pq; //min priority queue
int ans=0;
for(auto x:v)
pq.push(x);

while(pq.size()>1)
{
    int e1=pq.top();
    pq.pop();
    int e2=pq.top();
    pq.pop();
    
    ans+=e1+e2;
    
    cout<<e1<<" "<<e2<<endl;
    
    pq.push(e1+e2);
}
cout<<ans<<endl;

    return 0;
}
