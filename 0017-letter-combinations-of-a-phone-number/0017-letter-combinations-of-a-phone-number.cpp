class Solution {
public:
    vector<string> ans;
    string path;

    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (char ch : mp[digits[idx] - '0']) {
            path.push_back(ch);
            backtrack(digits, idx + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        backtrack(digits, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna