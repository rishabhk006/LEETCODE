class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums)
            ans.push_back(x);

        for (int x : nums)
            ans.push_back(x);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna