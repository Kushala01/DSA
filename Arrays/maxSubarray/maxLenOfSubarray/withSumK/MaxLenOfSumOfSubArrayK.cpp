class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int left=0,right=0;
        int maxi=0;
        long long sum=A[0];
        while(right<N){
            while(left<=right && sum>K){
                sum-=A[left];
                left++;
            }
            if(sum==K){
                maxi=max(maxi,right-left+1);
            }
            right++;
            if(right<N) sum+=A[right];
        }
        return maxi;
    } 
};