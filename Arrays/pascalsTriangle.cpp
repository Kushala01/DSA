class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;

        for(int i = 0; i < numRows; i++) {
            vector<int> pq;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    pq.push_back(1);
                } else {
                    int ele = dp[i - 1][j] + dp[i - 1][j - 1];
                    pq.push_back(ele);
                }
            }
            dp.push_back(pq);
        }
        
        return dp;
    }
};