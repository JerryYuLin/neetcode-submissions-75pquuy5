class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int r = board.size();
        int c = board[0].size();

        for (int i=0; i<r; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '_';
                q.push({i, 0});
            }
            if (board[i][c-1] == 'O') {
                board[i][c-1] = '_';
                q.push({i, c-1});
            }
        }

        for (int i=1; i<c-1; ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = '_';
                q.push({0, i});
            }
            if (board[r-1][i] == 'O') {
                board[r-1][i] = '_';
                q.push({r-1, i});
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            for (int i=0; i<4; ++i) {
                int x = p.first + dx[i], y = p.second + dy[i];

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
