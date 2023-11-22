#include <iostream>
using namespace std;

int longestKSubstr(string s, int k){
      int i = 0,j = 0;
      unordered_map<char,int> mpp;
      int ans = -1;
      while(j<s.size()){
          mpp[s[j]]++;
          if(mpp.size()<k){
            j++;
          }else if(mpp.size()==k){
              ans = max(ans,j-i+1);
              j++;
          }else{
              while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                      mpp.erase(s[i]);
                }i++;
              }j++;
          }
      }return ans;
}
