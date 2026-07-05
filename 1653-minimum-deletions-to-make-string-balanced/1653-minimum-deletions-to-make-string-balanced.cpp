class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0;

        for (char c : s)
            if (c == 'a')
                a++;

        int b = 0;
        int ans = a;

        for (char c : s) {
            if (c == 'a')
                a--;
            else
                b++;

            ans = min(ans, a + b);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna