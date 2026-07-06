class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> vis;

    void solve(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])
                continue;

            vis[i] = true;
            temp.push_back(nums[i]);

            solve(nums);

            temp.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vis.resize(nums.size(), false);

        solve(nums);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna