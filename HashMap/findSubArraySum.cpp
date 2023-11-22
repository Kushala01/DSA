class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        int res=0, currSum=0;
        unordered_map<int, int> prevSum;
        for(int i=0;i<N; i++){
            currSum+=Arr[i];
            if(currSum==k){
                res++;
            }
            if(prevSum.find(currSum - k) != prevSum.end()){
                res+=prevSum[currSum-k];
            }
            prevSum[currSum]++;
        }
        return res;
    }
};