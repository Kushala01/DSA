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
/*Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, 
we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the
 worst case. So, the time complexity is O(2*N) instead of O(N2).

Space Complexity: O(N), as we are using the set data structure to solve this problem.*/