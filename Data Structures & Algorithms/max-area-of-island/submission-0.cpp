class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1) dfs(grid, i, j);

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        int area = 1;
        stack<pair<int, int>> land;
        land.push({x, y});
        grid[x][y] = -1;

        while(!land.empty()) {
            auto p = land.top();
            land.pop();

            int i = p.first, j = p.second;

            if (i-1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = -1;
                land.push({i-1, j});
                ++area;
            }

            if (i+1 < grid.size() && grid[i+1][j] == 1) {
                grid[i+1][j] = -1;
                land.push({i+1, j});
                ++area;
            }

            if (j-1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = -1;
                land.push({i, j-1});
                ++area;
            }

            if (j+1 < grid[0].size() && grid[i][j+1] == 1) {
                grid[i][j+1] = -1;
                land.push({i, j+1});
                ++area;
            }
        }

        if (area > maxArea) maxArea = area;
    }
private:
    int maxArea = 0;
};
