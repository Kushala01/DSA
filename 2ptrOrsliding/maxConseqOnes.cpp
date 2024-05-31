class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
     {
       int ans=0;
       int i=0;
       int j=0;
       int maxi=0;
       while(j<nums.size())
       {
          if(nums[i]==1 && nums[j]==1)
          {
              ans++;
            maxi=max(maxi,ans);
          }
          else{
              i=j+1;
              ans=0;
            }
        j++;
       }    
       return maxi;
    }
};