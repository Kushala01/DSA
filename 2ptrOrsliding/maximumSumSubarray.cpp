 long maximumSumSubarray(int k, vector<int> &arr , int n){
        long sum=0,ans=0;
        int i=0,j=0;
        while(j<n){
            sum+=arr[j];
            if((j-i+1)==k){
                ans=max(ans,sum);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
