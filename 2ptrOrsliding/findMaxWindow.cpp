#include <bits/stdc++.h>
using namespace std;

int findMaxWindow(vector<int>&stocks,int n,int k){
    int ans=-1,sum=0;
    int i=0,j=0;
    unordered_map<int,int>mpp;
    while(j<n){
        sum+=stocks[j];
        mpp[stocks[j]]++;
       if(j-i+1<k)  j++;
       else if(j-i+1==k){
           if(mpp.size()==k) ans=max(ans,sum);
           sum-=stocks[i];
           mpp[stocks[i]]--;
           if(mpp[stocks[i]]==0) mpp.erase(stocks[i]);
           i++;
           j++;
       }
    }return ans;
}

int main() {
    int n,k;
    cin>>n;
    vector<int>stocks(n);
    for(int i=0;i<n;i++) cin>>stocks[i];
    cin>>k;
    cout<<findMaxWindow(stocks,n,k)<<endl;
}/*
Input:
n=7
stocks[]={1 2 7 7 4 3 6}
k=3
Output:14*/
