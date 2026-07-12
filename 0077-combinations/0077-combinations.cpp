class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int start, int n, int k) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.push_back(i);
            dfs(i + 1, n, k);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna