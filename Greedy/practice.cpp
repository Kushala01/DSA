#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

class Solution{
    public:
    static bool comparator(struct meeting A, struct meeting B){
        if(A.end<B.end) return true;
        else if(A.end>B.end) return false;
        else if(A.pos<B.pos) return true;
        return false;
    }

    vector<int> maxMeetings(int s[],int e[],int n){
        struct meeting m[n];
        for(int i=0;i<n;i++){
            m[i].start=s[i];
            m[i].end=e[i];
            m[i].pos=i+1;
        }

        sort(m, m+n, comparator);
        vector<int> ans;
        int limit=m[0].end;
        ans.push_back(m[0].pos);

        for(int i=1;i<n;i++){
            if(m[i].start>limit){
            limit=m[i].end;
            ans.push_back(m[i].pos);
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    int s[]={1,3,0,5,8,5};
    int end[] = {2,4,5,7,9,9};
    int n=sizeof(s)/sizeof(s[0]);
    vector<int>ans=obj.maxMeetings(s,end,n);
    cout<<"the order is as follows: "<<endl;
    for(auto it: ans)
        cout<<it<<endl;
   return 0;
}