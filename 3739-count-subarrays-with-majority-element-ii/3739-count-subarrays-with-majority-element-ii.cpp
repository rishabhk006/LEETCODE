class BinaryIndexedTree {
public:
    int n;
    vector<int> bit;

    BinaryIndexedTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        BinaryIndexedTree bit(2 * n + 1);

        int pref = n + 1;
        bit.update(pref, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += bit.query(pref - 1);
            bit.update(pref, 1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna