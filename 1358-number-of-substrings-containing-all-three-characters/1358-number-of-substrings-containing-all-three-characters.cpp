class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int left = 0, ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] && cnt[1] && cnt[2]) {
                ans += n - right;
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna