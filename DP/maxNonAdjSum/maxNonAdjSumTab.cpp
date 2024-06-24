class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int ind=1;ind<n;ind++){
          int pick=nums[ind];
          if(ind>1) pick+=dp[ind-2];
          int notPick=dp[ind-1];
          dp[ind]=max(pick,notPick);
        }
        return dp[n-1];
    }
};