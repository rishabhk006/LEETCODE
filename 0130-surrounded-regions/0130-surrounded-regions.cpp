class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i,0});
                board[i][0] = '#';
            }
            if (board[i][m-1] == 'O') {
                q.push({i,m-1});
                board[i][m-1] = '#';
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0,j});
                board[0][j] = '#';
            }
            if (board[n-1][j] == 'O') {
                q.push({n-1,j});
                board[n-1][j] = '#';
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'O') {
                    board[nx][ny] = '#';
                    q.push({nx,ny});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna