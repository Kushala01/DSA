#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSeq(vector<int>&a){
    int n=a.size();
    if(n==0) return n;
    int count,longest=1;
    int x;

    unordered_set<int> st;

    for(int i=0;i<n;i++) st.insert(a[i]);

    for(auto it : st){
        if(st.find(it-1)==st.end()){
            count=1;
            x=it;
            while(st.find(x+1)!=st.end()){
                x+=1;
                count+=1;
            }longest=max(longest,count);
        }
    }return longest;
}

int main(){
    vector<int>a={1,2,3,4,5,6,7};
    int ans=findLongestConseqSeq(a);
    cout<<"the longest suquence is"<<ans<<"\n";
    return 0;
}