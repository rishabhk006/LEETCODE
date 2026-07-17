class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1);
        for (int x : nums)
            cnt[x]++;

        vector<long long> pairs(mx + 1);

        for (int g = mx; g >= 1; g--) {
            long long total = 0;

            for (int j = g; j <= mx; j += g) {
                total += cnt[j];
                pairs[g] -= pairs[j];
            }

            pairs[g] += total * (total - 1) / 2;
        }

        for (int i = 2; i <= mx; i++)
            pairs[i] += pairs[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            ans.push_back(upper_bound(pairs.begin(), pairs.end(), q) - pairs.begin());
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna