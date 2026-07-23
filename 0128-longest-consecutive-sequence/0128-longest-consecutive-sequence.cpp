class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (!st.count(num - 1)) {
                int curr = num;
                int len = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna