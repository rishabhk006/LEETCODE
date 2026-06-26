class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        long long rev = 0;

        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return original == rev;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna