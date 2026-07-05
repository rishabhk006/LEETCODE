class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.size()) {
            if (j < p.size() && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
            else if (j < p.size() && p[j] == '*') {
                star = j++;
                match = i;
            }
            else if (star != -1) {
                j = star + 1;
                i = ++match;
            }
            else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*')
            j++;

        return j == p.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna