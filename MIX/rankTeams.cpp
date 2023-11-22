#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // m is the number of teams in each vote
        int m = votes[0].size();
        
        // 2D vector to calculate total votes for each ranking for each team
        vector<vector<int>> mp(26, vector<int>(m, 0));
        
        // Counting the votes for each team at each rank
        for (string& voter : votes) {
            for (int i = 0; i < voter.length(); i++) {
                mp[voter[i] - 'A'][i]++;
            }
        }

        // To store the rank chart against each team
        vector<pair<vector<int>, char>> table(26);

        // Filling the rank chart for each team
        for (int i = 0; i < 26; i++) {
            table[i] = {mp[i], (i + 'A')};
        }

        // Sorting the teams based on their ranks and then alphabetically
        sort(table.begin(), table.end(), [](pair<vector<int>, char>& a, pair<vector<int>, char>& b) {
            return (a.first > b.first) || (a.first == b.first && a.second < b.second);
        });

        // Building the answer string based on sorted teams
        string ans = "";
        for (int i = 0; i < min(26, m); i++) { // Loop up to the number of teams
            ans += table[i].second; // Adding team character to the answer
        }

        return ans; // Returning the final ranking of the teams
    }
};

int main() {
    vector<string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
    Solution solution;
    cout << "Ranking of teams: " << solution.rankTeams(votes) << endl;
    return 0;
}