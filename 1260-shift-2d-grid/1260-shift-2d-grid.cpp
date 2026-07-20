class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int total = n * m;
        k %= total;

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < total; i++) {
            int ni = (i + k) % total;
            ans[ni / m][ni % m] = grid[i / m][i % m];
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna