class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        long long x = 0;
        int sum = 0;

        for (char c : s) {
            if (c != '0') {
                x = x * 10 + (c - '0');
                sum += c - '0';
            }
        }

        return x * sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna