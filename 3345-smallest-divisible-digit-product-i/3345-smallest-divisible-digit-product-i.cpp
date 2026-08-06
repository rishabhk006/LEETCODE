class Solution {
public:
    int digitProduct(int x) {
        int product = 1;
        while (x > 0) {
            product *= (x % 10);
            x /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (digitProduct(n) % t == 0)
                return n;
            n++;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna