class Solution {
public:
    vector<string> ans;

    void solve(string &s, int idx, int part, string cur) {
        if (part == 4 && idx == s.size()) {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }

        if (part == 4 || idx == s.size())
            return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string t = s.substr(idx, len);

            if ((t[0] == '0' && t.size() > 1) || stoi(t) > 255)
                continue;

            solve(s, idx + len, part + 1, cur + t + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna