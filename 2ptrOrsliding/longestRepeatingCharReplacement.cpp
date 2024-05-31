class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int i=0;
        int j=0;
        int ans=-1;
        int  maxi=0;
        unordered_map<char, int>mp;
        while(j<n) {
            mp[s[j]]++;
            maxi= max(maxi, mp[s[j]]);
            if((j-i+1)-maxi<=k){
                 ans= max(ans,j-i+1);
            }
            else {
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};