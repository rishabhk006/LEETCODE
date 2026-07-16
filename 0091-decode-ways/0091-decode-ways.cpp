class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = (s[0] != '0');

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna