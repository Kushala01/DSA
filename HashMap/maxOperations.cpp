class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int,int> kk,gg; 
        int i = 0 ; 
        int n = nums.size();
        while(i<n){
            kk[nums[i]]=kk[nums[i]]+1;
            i=i+1;
        }
        int answer = 0 ; 
        for(i=0;i<n;i++){
            int number = nums[i] ; 
            int partner = k - number ; 
            if(gg[number]==0 && gg[partner]==0){
                if(number==partner){
                    int yy = kk[number];
                    answer = answer + (yy/2);
                }
                else{
                    answer = answer + min(kk[number],kk[partner]);
                }
            }
            gg[number]=1;
            gg[partner]=1;
        }
        return answer ; 
    }
};
