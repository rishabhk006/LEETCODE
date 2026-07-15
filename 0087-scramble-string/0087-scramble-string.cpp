class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string a, string b) {
        if (a == b) return true;
        if (a.size() != b.size()) return false;

        string key = a + "#" + b;
        if (dp.count(key)) return dp[key];

        string x = a, y = b;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x != y)
            return dp[key] = false;

        int n = a.size();

        for (int i = 1; i < n; i++) {
            if (solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i), b.substr(i)))
                return dp[key] = true;

            if (solve(a.substr(0, i), b.substr(n - i)) &&
                solve(a.substr(i), b.substr(0, n - i)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna