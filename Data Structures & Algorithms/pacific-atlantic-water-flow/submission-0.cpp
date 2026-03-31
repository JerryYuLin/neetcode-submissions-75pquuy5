class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i=0; i<heights[0].size(); ++i) {
            stack<vector<int>> s;
            s.push({0, i});
            pacific[0][i] = true;

            while(!s.empty()) {
                vector<int> p = s.top();
                s.pop();

                for (int j=0; j<4; ++j) {
                    int r = p[0] + dx[j];
                    int c = p[1] + dy[j];

                    if (
                        r >= 0 && r < heights.size() &&
                        c >= 0 && c < heights[0].size() &&
                        !pacific[r][c] &&
                        heights[r][c] >= heights[p[0]][p[1]]
                    ) {
                        s.push({r, c});
                        pacific[r][c] = true;
                    }
                }
            }
        }

        for (int i=0; i<heights.size(); ++i) {
            stack<vector<int>> s;
            s.push({i, 0});
            pacific[i][0] = true;

            while(!s.empty()) {
                vector<int> p = s.top();
                s.pop();

                for (int j=0; j<4; ++j) {
                    int r = p[0] + dx[j];
                    int c = p[1] + dy[j];

                    if (
                        r >= 0 && r < heights.size() &&
                        c >= 0 && c < heights[0].size() &&
                        !pacific[r][c] &&
                        heights[r][c] >= heights[p[0]][p[1]]
                    ) {
                        s.push({r, c});
                        pacific[r][c] = true;
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for (int i=0; i<heights[heights.size()-1].size(); ++i) {
            stack<vector<int>> s;
            s.push({heights.size()-1, i});
            if (pacific[heights.size()-1][i]) ans.push_back({heights.size()-1, i});
            atlantic[heights.size()-1][i] = true;

            while(!s.empty()) {
                vector<int> p = s.top();
                s.pop();

                for (int j=0; j<4; ++j) {
                    int r = p[0] + dx[j];
                    int c = p[1] + dy[j];

                    if (
                        r >= 0 && r < heights.size() &&
                        c >= 0 && c < heights[0].size() &&
                        !atlantic[r][c] &&
                        heights[r][c] >= heights[p[0]][p[1]]
                    ) {
                        s.push({r, c});
                        atlantic[r][c] = true;
                        if (pacific[r][c]) ans.push_back({r, c});
                    }
                }
            }
        }

        for (int i=0; i<heights.size(); ++i) {
            stack<vector<int>> s;
            s.push({i, heights[0].size()-1});
            atlantic[i][heights[0].size()-1] = true;
            if (pacific[i][heights[0].size()-1]) ans.push_back({i, heights[0].size()-1});

            while(!s.empty()) {
                vector<int> p = s.top();
                s.pop();

                for (int j=0; j<4; ++j) {
                    int r = p[0] + dx[j];
                    int c = p[1] + dy[j];

                    if (
                        r >= 0 && r < heights.size() &&
                        c >= 0 && c < heights[0].size() &&
                        !atlantic[r][c] &&
                        heights[r][c] >= heights[p[0]][p[1]]
                    ) {
                        s.push({r, c});
                        atlantic[r][c] = true;
                        if (pacific[r][c]) ans.push_back({r, c});
                    }
                }
            }
        }

        set<vector<int>> s(ans.begin(), ans.end());

        return vector<vector<int>>(s.begin(), s.end());
    }
};
