class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        int curr;
        int prev=nums[0];
        int prev_2=0;
        for(int ind=1;ind<n;ind++){
          int pick=nums[ind];
          if(ind>1) pick+=prev_2;
          int notPick=0+prev;
          curr=max(pick,notPick);
          prev_2=prev;
          prev=curr;
        }
        return prev;
    }
};