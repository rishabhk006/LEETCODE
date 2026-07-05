class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        int dx[] = {1, 0, 1};
        int dy[] = {0, 1, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1))
                    continue;

                int best = -1;
                int cnt = 0;

                for (int k = 0; k < 3; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= n || nj >= n || score[ni][nj] == -1)
                        continue;

                    if (score[ni][nj] > best) {
                        best = score[ni][nj];
                        cnt = ways[ni][nj];
                    } else if (score[ni][nj] == best) {
                        cnt = (cnt + ways[ni][nj]) % MOD;
                    }
                }

                if (best == -1)
                    continue;

                score[i][j] = best;
                ways[i][j] = cnt;

                if (board[i][j] != 'S' && board[i][j] != 'E')
                    score[i][j] += board[i][j] - '0';
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna