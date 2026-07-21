class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0, pre = INT_MIN, mx = 0;

        for (int i = 0, n = s.size(); i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;

            if (s[i] == '1')
                ans += len;
            else {
                mx = max(mx, pre + len);
                pre = len;
            }
            i = j;
        }

        return ans + mx;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna