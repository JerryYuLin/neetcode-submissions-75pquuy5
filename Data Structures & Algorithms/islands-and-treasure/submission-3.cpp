class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 0) q.push({i, j});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;

            for (int k = 0; k < 4; ++k) {
                int m = x + dx[k], n = y + dy[k];
                if (
                    m >= 0 && m < grid.size() &&
                    n >= 0 && n < grid[0].size() &&
                    grid[m][n] == 2147483647
                ) {
                    grid[m][n] = grid[x][y] + 1;
                    q.push({m, n});
                }
            }
        }
    }
};
