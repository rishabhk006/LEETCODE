class Solution {
public:
    void fwht(vector<long long>& a) {
        int n = a.size();
        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += len << 1) {
                for (int j = 0; j < len; j++) {
                    long long u = a[i + j];
                    long long v = a[i + j + len];
                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                }
            }
        }
    }

    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<long long> a(MAXX, 0);
        unordered_set<int> st(nums.begin(), nums.end());

        for (int x : st)
            a[x] = 1;

        fwht(a);

        for (int i = 0; i < MAXX; i++)
            a[i] = a[i] * a[i] * a[i];

        fwht(a);

        int ans = 0;
        for (int i = 0; i < MAXX; i++) {
            if (a[i] != 0)
                ans++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna