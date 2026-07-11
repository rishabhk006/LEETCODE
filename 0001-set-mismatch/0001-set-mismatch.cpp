class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<int> ans(2);

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2)
                ans[0] = i;
            else if (freq[i] == 0)
                ans[1] = i;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna