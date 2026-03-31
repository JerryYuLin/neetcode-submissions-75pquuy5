class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j] == '1') {
                    island++;
                    dfs(grid, i, j);
                }
            }
        
        return island;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        stack<pair<int, int>> s;
        s.push({x, y});
        grid[x][y] = '_';

        while(!s.empty()) {
            int i = s.top().first;
            int j = s.top().second;
            s.pop();

            if ((i-1) >= 0 && grid[i-1][j] == '1') {
                grid[i-1][j] = '_';
                s.push({i-1, j});
            }
            if ((i+1) < grid.size() && grid[i+1][j] == '1') {
                grid[i+1][j] = '_';
                s.push({i+1, j});
            }
            if ((j-1) >= 0 && grid[i][j-1] == '1') {
                grid[i][j-1] = '_';
                s.push({i, j-1});
            }
            if ((j+1) < grid[0].size() && grid[i][j+1] == '1') {
                grid[i][j+1] = '_';
                s.push({i, j+1});
            }
        }
    }
};
