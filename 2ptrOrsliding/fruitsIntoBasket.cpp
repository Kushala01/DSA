
#include<bits/stdc++.h>
class Solution {
  public:
    int totalFruits(int N, vector<int> &arr) {
        int l=0,r=0,maxlength=0;
        unordered_map<int,int> m;
        while(r<N){
            m[arr[r]]++;
                if(m.size()>2){
                    m[arr[l]]--;
                    if(m[arr[l]]==0){
                        m.erase(arr[l]);
                    }
                    l++;
                }
            int length=r-l+1;
            maxlength=max(maxlength,length);
            r++;
        }
        return maxlength;
    }
};