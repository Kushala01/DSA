class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int maxlen=0;
        
        for(int i=0;i<N;i++)
        {
            set<int>st;
            for(int j=i;j<N;j++)
            {
                st.insert(fruits[j]);
                if(st.size()>2) break;
                maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};