class Solution {
public:
    int R, C;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && 
                !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        R = heights.size();
        C = heights[0].size();
        vector<vector<bool>> pacific(R, vector<bool>(C, false));
        vector<vector<bool>> atlantic(R, vector<bool>(C, false));

        // 從左右邊界開始爬
        for (int i = 0; i < R; i++) {
            dfs(heights, pacific, i, 0);       // 左：太平洋
            dfs(heights, atlantic, i, C - 1);  // 右：大西洋
        }
        // 從上下邊界開始爬
        for (int j = 0; j < C; j++) {
            dfs(heights, pacific, 0, j);       // 上：太平洋
            dfs(heights, atlantic, R - 1, j);  // 下：大西洋
        }

        vector<vector<int>> ans;
        // 最後掃一遍：兩者皆為 true 的就是交集
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};