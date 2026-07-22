class Seg {
public:
    int lo, hi, best;
    Seg *left, *right;

    Seg(vector<int>& pos, int l, int r) {
        lo = pos[l];
        hi = pos[r];
        best = 0;
        left = right = nullptr;

        if (l != r) {
            int m = (l + r) / 2;
            left = new Seg(pos, l, m);
            right = new Seg(pos, m + 1, r);
        }
    }

    void update(int p, int val) {
        if (p < lo || p > hi) return;
        best = max(best, val);
        if (left) {
            left->update(p, val);
            right->update(p, val);
        }
    }

    int query(int l, int r) {
        if (r < lo || hi < l) return 0;
        if (l <= lo && hi <= r) return best;
        return max(left->query(l, r), right->query(l, r));
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> le(n), ri(n);

        le[0] = 0;
        for (int i = 1; i < n; i++)
            le[i] = (s[i] == s[i - 1]) ? le[i - 1] : i;

        ri[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
            ri[i] = (s[i] == s[i + 1]) ? ri[i + 1] : i;

        auto valid = [&](int l, int r) {
            if (l >= n || r < 0 || l >= r) return false;
            return le[l] != le[r];
        };

        auto leftGain = [&](int l, int r) {
            int res = ri[l] - l + 1;
            l = ri[ri[l] + 1] + 1;
            res += min(r, ri[l]) - l + 1;
            return res;
        };

        auto rightGain = [&](int l, int r) {
            int res = r - le[r] + 1;
            r = le[le[r] - 1] - 1;
            res += r - max(l, le[r]) + 1;
            return res;
        };

        vector<int> pos, val;

        for (int i = 0; i < n; i++) {
            if (i && s[i] == s[i - 1]) continue;
            if (s[i] == '1') continue;
            pos.push_back(i);
            val.push_back(ri[i] - le[i] + 1);
        }

        int ones = count(s.begin(), s.end(), '1');

        if (pos.size() <= 1)
            return vector<int>(queries.size(), ones);

        for (int i = 0; i + 1 < val.size(); i++)
            val[i] += val[i + 1];

        Seg* seg = new Seg(pos, 0, pos.size() - 1);

        for (int i = 0; i < pos.size(); i++)
            seg->update(pos[i], val[i]);

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            if (s[l] == '1')
                l = ri[l] + 1;

            if (s[r] == '1')
                r = le[r] - 1;

            if (!valid(l, r)) {
                ans.push_back(ones);
                continue;
            }

            int cur = max(leftGain(l, r), rightGain(l, r));

            l = ri[ri[l] + 1] + 1;
            r = le[le[r] - 1] - 1;

            if (l <= r && le[l] != le[r])
                cur = max(cur, seg->query(l, le[r] - 1));

            ans.push_back(ones + cur);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna