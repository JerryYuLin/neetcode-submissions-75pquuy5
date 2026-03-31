class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;

        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j)
                if (grid[i][j] == 2) q.push({i, j, 0});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int maxTime = 0;

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = get<0>(p);
            int j = get<1>(p);
            int t = get<2>(p);

            for (int k=0; k<4; ++k)
                if (
                    i+dx[k]>=0 && i+dx[k]<grid.size() &&
                    j+dy[k]>=0 && j+dy[k]<grid[0].size() &&
                    grid[i+dx[k]][j+dy[k]] == 1
                ) {
                    grid[i+dx[k]][j+dy[k]] = 2;
                    q.push({i+dx[k], j+dy[k], t+1});
                    if (t+1>maxTime) maxTime = t+1;
                }
        }

        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j)
                if (grid[i][j] == 1) return -1;
        
        return maxTime;
    }
};
