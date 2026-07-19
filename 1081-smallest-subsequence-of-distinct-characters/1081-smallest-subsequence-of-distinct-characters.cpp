class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> vis(26, false);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string ans;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (vis[c]) continue;

            while (!ans.empty() &&
                   ans.back() > s[i] &&
                   last[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            vis[c] = true;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna