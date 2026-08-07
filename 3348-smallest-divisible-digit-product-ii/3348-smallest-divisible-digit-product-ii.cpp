#include <string>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
    int dp[55][35];

    int get_min_len(int r2, int r3, int r5, int r7) {
        // Fix: clamp r5 and r7 to 0 to prevent negative values from offsetting the length
        return max(0, r5) + max(0, r7) + dp[max(0, r2)][max(0, r3)];
    }

    bool check(int length, int r2, int r3, int r5, int r7) {
        return get_min_len(r2, r3, r5, r7) <= length;
    }

    string build(int length, int r2, int r3, int r5, int r7) {
        string res = "";
        for (int pos = 0; pos < length; ++pos) {
            for (int d = 1; d <= 9; ++d) {
                int dc2 = (d == 2 || d == 6) ? 1 : ((d == 4) ? 2 : ((d == 8) ? 3 : 0));
                int dc3 = (d == 3 || d == 6) ? 1 : ((d == 9) ? 2 : 0);
                int dc5 = (d == 5) ? 1 : 0;
                int dc7 = (d == 7) ? 1 : 0;

                int nr2 = max(0, r2 - dc2);
                int nr3 = max(0, r3 - dc3);
                int nr5 = max(0, r5 - dc5);
                int nr7 = max(0, r7 - dc7);

                if (check(length - 1 - pos, nr2, nr3, nr5, nr7)) {
                    res += to_string(d);
                    r2 = nr2;
                    r3 = nr3;
                    r5 = nr5;
                    r7 = nr7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int R2 = 0, R3 = 0, R5 = 0, R7 = 0;
        while (temp % 2 == 0) { R2++; temp /= 2; }
        while (temp % 3 == 0) { R3++; temp /= 3; }
        while (temp % 5 == 0) { R5++; temp /= 5; }
        while (temp % 7 == 0) { R7++; temp /= 7; }

        if (temp > 1) return "-1";

        const int MAX2 = 52;
        const int MAX3 = 34;
        for (int i = 0; i < MAX2; ++i) {
            for (int j = 0; j < MAX3; ++j) {
                dp[i][j] = 1e9;
            }
        }
        dp[0][0] = 0;

        int moves[6][3] = {{2, 1, 0}, {3, 0, 1}, {4, 2, 0}, {6, 1, 1}, {8, 3, 0}, {9, 0, 2}};
        for (int i = 0; i < MAX2; ++i) {
            for (int j = 0; j < MAX3; ++j) {
                if (dp[i][j] == 1e9) continue;
                for (auto& m : moves) {
                    int ni = min(MAX2 - 1, i + m[1]);
                    int nj = min(MAX3 - 1, j + m[2]);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
                }
            }
        }

        for (int i = MAX2 - 1; i >= 0; --i) {
            for (int j = MAX3 - 1; j >= 0; --j) {
                if (i + 1 < MAX2) dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                if (j + 1 < MAX3) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }

        int N = num.length();
        vector<array<int, 4>> p_factors(N);
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        int max_i = N - 1;
        bool has_zero = false;

        for (int i = 0; i < N; ++i) {
            if (num[i] == '0') {
                if (!has_zero) {
                    max_i = i;
                    has_zero = true;
                }
                p_factors[i] = {c2, c3, c5, c7};
                continue;
            }
            
            int d = num[i] - '0';
            if (d == 2 || d == 6) c2 += 1;
            else if (d == 4) c2 += 2;
            else if (d == 8) c2 += 3;

            if (d == 3 || d == 6) c3 += 1;
            else if (d == 9) c3 += 2;

            if (d == 5) c5 += 1;
            if (d == 7) c7 += 1;

            p_factors[i] = {c2, c3, c5, c7};
        }

        if (!has_zero && get_min_len(R2 - c2, R3 - c3, R5 - c5, R7 - c7) == 0) {
            return num;
        }

        for (int i = max_i; i >= 0; --i) {
            int curr_c2 = (i > 0) ? p_factors[i - 1][0] : 0;
            int curr_c3 = (i > 0) ? p_factors[i - 1][1] : 0;
            int curr_c5 = (i > 0) ? p_factors[i - 1][2] : 0;
            int curr_c7 = (i > 0) ? p_factors[i - 1][3] : 0;

            for (int d = (num[i] - '0') + 1; d <= 9; ++d) {
                int dc2 = (d == 2 || d == 6) ? 1 : ((d == 4) ? 2 : ((d == 8) ? 3 : 0));
                int dc3 = (d == 3 || d == 6) ? 1 : ((d == 9) ? 2 : 0);
                int dc5 = (d == 5) ? 1 : 0;
                int dc7 = (d == 7) ? 1 : 0;

                int rem2 = max(0, R2 - curr_c2 - dc2);
                int rem3 = max(0, R3 - curr_c3 - dc3);
                int rem5 = max(0, R5 - curr_c5 - dc5);
                int rem7 = max(0, R7 - curr_c7 - dc7);

                if (check(N - 1 - i, rem2, rem3, rem5, rem7)) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = build(N - 1 - i, rem2, rem3, rem5, rem7);
                    return prefix + suffix;
                }
            }
        }

        int L = max(N + 1, get_min_len(R2, R3, R5, R7));
        return build(L, R2, R3, R5, R7);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna