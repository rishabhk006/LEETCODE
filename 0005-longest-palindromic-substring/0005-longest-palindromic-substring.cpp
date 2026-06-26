class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            expand(s, i, i, start, maxLen);
            expand(s, i, i + 1, start, maxLen);
        }
        
        return s.substr(start, maxLen);
    }

private:
    void expand(string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        int currentLen = right - left - 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
            start = left + 1;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna