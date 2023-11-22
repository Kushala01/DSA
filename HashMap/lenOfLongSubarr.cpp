class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int, int>mp;
        int sum=0, maxLen=0,len=0;
        for(int i=0; i<N; i++){
            sum+=A[i];
            if(sum==k){
                len=i+1;
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            if(mp.find(sum-k)!=mp.end()){
                len=i-mp[sum-k];
            }
            maxLen=max(maxLen,len);
        }
        return maxLen;
    } 

};
