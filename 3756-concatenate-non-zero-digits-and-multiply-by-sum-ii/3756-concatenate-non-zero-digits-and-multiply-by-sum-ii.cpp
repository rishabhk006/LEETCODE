class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
         const int MOD = 1000000007;
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> pref(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<int> digitSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            digitSum[i + 1] = digitSum[i] + (s[i] - '0');
            cnt[i + 1] = cnt[i];
            pref[i + 1] = pref[i];

            if (s[i] != '0') {
                cnt[i + 1]++;
                pref[i + 1] = (pref[i] * 10 + (s[i] - '0')) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int sum = digitSum[r + 1] - digitSum[l];
            int c = cnt[r + 1] - cnt[l];

            long long x = (pref[r + 1] -
                          pref[l] * pow10[c] % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna