class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;

        if (p < 0) {
            x = 1 / x;
            p = -p;
        }

        double ans = 1.0;

        while (p > 0) {
            if (p % 2 == 1)
                ans *= x;

            x *= x;
            p /= 2;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna