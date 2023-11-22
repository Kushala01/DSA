// Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/
// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int longest_cons_chain = 0;
    unordered_map<int, bool> present;
    unordered_map<int, bool> checked;
    for (auto a : nums)
    {
        present[a] = true;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        // !checked[nums[i]] means that number should not be part of a conseq sequence made already
        if (!checked[nums[i]] && !present[nums[i] - 1])
        {
            int current_chain = 0;
            int start = nums[i];
            while (present[start])
            {
                current_chain++;
                checked[start] = true;
                start++;
            }
            longest_cons_chain = max(longest_cons_chain, current_chain);
        }
    }
    return longest_cons_chain;
}

int main()
{
    vector<int> nums{100, 4, 200, 1, 3, 2};
    int answer = longestConsecutive(nums);
    cout << "The ans is " << answer << endl;
    return 0;
}
