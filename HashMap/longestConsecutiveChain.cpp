class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest_cons_chain=0;
        unordered_map <int, bool> present;
        unordered_map <int, bool> checked;

        for(auto i : nums){
            present[i]=true;
        }
        for(auto i : nums){
            if(!checked[i] && present[i]){
                int start=i;
                int chain=0;
                while(present[start]){
                    checked[start]=true;
                    chain++;
                    start++;
                }
                longest_cons_chain=max(chain, longest_cons_chain);
            }
        }
        return longest_cons_chain;
    }
};
