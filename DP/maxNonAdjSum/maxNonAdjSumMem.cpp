class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        vector<int>dp(n,-1);
        int ans=findTotalRobbings(nums,n-1,dp);
        return ans;
    }
    //mem
    int findTotalRobbings(vector<int>&arr, int ind, vector<int>&dp){
          if(ind<0) return 0;
          if(ind==0) return arr[ind];
          if(dp[ind]!=-1) return dp[ind];

          int pick=findTotalRobbings(arr,ind-2,dp)+arr[ind];
          int notPick=findTotalRobbings(arr,ind-1,dp);

          return dp[ind]=max(pick,notPick);
    }
};