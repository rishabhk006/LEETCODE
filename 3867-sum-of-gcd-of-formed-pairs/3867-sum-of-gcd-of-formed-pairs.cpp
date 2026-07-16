class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            a[i] = gcd(nums[i], mx);
        }

        sort(a.begin(), a.end());

        long long ans = 0;
        for (int i = 0; i < n / 2; i++)
            ans += gcd(a[i], a[n - 1 - i]);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna