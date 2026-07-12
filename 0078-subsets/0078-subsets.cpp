class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int idx, vector<int>& nums) {
        ans.push_back(cur);

        for (int i = idx; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(i + 1, nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna