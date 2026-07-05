class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            while ((long long)nums[right] > 1LL * nums[left] * k)
                left++;

            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna