class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 0) {
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                    queue<tuple<int, int, int>> q;
                    q.push({i, j, 0});
                    visited[i][j] = true;

                    int dx[] = {1, -1, 0, 0};
                    int dy[] = {0, 0, 1, -1};

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int x = get<0>(p), y = get<1>(p), d = get<2>(p);

                        for (int k = 0; k < 4; ++k) {
                            int m = x + dx[k], n = y + dy[k];
                            if (
                                m >= 0 && m < grid.size() &&
                                n >= 0 && n < grid[0].size() &&
                                !visited[m][n] &&
                                grid[m][n] > d+1
                            ) {
                                grid[m][n] = d+1;
                                visited[m][n] = true;
                                q.push({m, n, d+1});
                            }
                        }
                    }
                }
    }
};
