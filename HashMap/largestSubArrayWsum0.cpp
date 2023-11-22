    int maxLen(vector<int>&A, int n)
    {   
        int sum=0;
        int longest_length=0;
        unordered_map<int, int> mpp;
        for(int i=0; i<A.size(); i++){
        sum+=A[i];
        if(sum==0){
            longest_length=i;
        }
        else{
        if(mpp.find(sum)!=mpp.end()){
            longest_length=max(longest_length, i-mpp[sum]);
        }
        else
        mpp[sum]=i;
    }
    
        }
        return longest_length;
    }