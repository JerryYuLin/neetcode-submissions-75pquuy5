class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        queue<pair<int, int>> q;
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                bool isEdge = (i == 0 || i == r - 1 || j == 0 || j == c - 1);
                if (isEdge && board[i][j] == 'O') {
                    board[i][j] = '_';
                    q.push({i, j});
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            for (int i=0; i<4; ++i) {
                auto [x, y] = p;
                x = x + dx[i], y = y + dy[i];

                if (
                    x >= 0 && x < r && y >= 0 && y < c &&
                    board[x][y] == 'O'
                ) {
                    board[x][y] = '_';
                    q.push({x, y});
                }
            }
        }

        for (int i=0; i<r; ++i)
            for (int j=0; j<c; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '_') board[i][j] = 'O';
    }
};
