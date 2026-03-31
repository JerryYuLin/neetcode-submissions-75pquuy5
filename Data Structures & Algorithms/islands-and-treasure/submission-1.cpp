class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 2147483647) {
                    queue<tuple<int, int, int>> q;
                    int rows = grid.size();
                    int cols = grid[0].size();

                    // 建立一個 rows x cols 的二維 vector，並初始化所有值為 false
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                    q.push({i, j, 0});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int x = get<0>(p);
                        int y = get<1>(p);
                        int d = get<2>(p);

                        if (grid[x][y] == 0) {
                            grid[i][j] = d;
                            break;
                        }
                        else {
                            if (x-1 >= 0 && !visited[x-1][y] && grid[x-1][y] != -1) {
                                visited[x-1][y] = true;
                                q.push({x-1, y , d+1});
                            }
                            if (x+1 < grid.size() && !visited[x+1][y] && grid[x+1][y] != -1) {
                                visited[x+1][y] = true;
                                q.push({x+1, y, d+1});
                            }
                            if (y-1 >= 0 && !visited[x][y-1] && grid[x][y-1] != -1) {
                                visited[x][y-1] = true;
                                q.push({x, y-1, d+1});
                            }
                            if (y+1 < grid[0].size() && !visited[x][y+1] && grid[x][y+1] != -1) {
                                visited[x][y+1] = true;
                                q.push({x, y+1, d+1});
                            }
                        }
                    }
                }
    }
};
