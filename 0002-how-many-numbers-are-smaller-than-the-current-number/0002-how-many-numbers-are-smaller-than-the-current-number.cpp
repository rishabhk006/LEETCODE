class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < temp.size(); i++) {
            if (!mp.count(temp[i]))
                mp[temp[i]] = i;
        }

        vector<int> ans;

        for (int x : nums)
            ans.push_back(mp[x]);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna