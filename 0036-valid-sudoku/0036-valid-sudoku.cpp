class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9), col(9), box(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int b = (i / 3) * 3 + (j / 3);

                if (row[i].count(board[i][j]) ||
                    col[j].count(board[i][j]) ||
                    box[b].count(board[i][j]))
                    return false;

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[b].insert(board[i][j]);
            }
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna