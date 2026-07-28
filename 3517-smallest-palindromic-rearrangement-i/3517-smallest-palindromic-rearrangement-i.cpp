class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string half = "";
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half.append(cnt[i] / 2, char('a' + i));
            if (cnt[i] % 2)
                mid = char('a' + i);
        }

        string ans = half;

        if (mid)
            ans += mid;

        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna