#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    
    int rows = grid.size(), cols = grid[0].size();
    int days = 0, totalOranges = 0, rottenOrangesCount = 0;
    
    queue<pair<int, int>> rottenQueue;
    
    // Count total oranges and enqueue initial rotten oranges
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            if(grid[i][j] != 0) totalOranges++;
            if(grid[i][j] == 2) rottenQueue.push({i, j});
        }
    }
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    // BFS to spread rot to adjacent fresh oranges
    while(!rottenQueue.empty()){
        int currentLevelSize = rottenQueue.size();
        rottenOrangesCount += currentLevelSize;
        
        while(currentLevelSize--){
            int x = rottenQueue.front().first, y = rottenQueue.front().second;
            rottenQueue.pop();
            
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                rottenQueue.push({nx, ny});
            }
        }
        
        if(!rottenQueue.empty()) days++;
    }
    
    return totalOranges == rottenOrangesCount ? days : -1;
}

int main()
{
    vector<vector<int>> grid { {2,1,1} , {1,1,0} , {0,1,1} };
    int result = orangesRotting(grid);
    cout << "Minimum Number of Minutes Required: " << result << endl;
    return 0;
}