class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = position of word2[i] in a valid
        // subsequence matching word2[i...m-1]
        vector<int> suf(m, n);

        int j = n - 1;

        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && word1[j] != word2[i])
                j--;

            if (j >= 0) {
                suf[i] = j;
                j--;
            }
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int i = 0; i < m; i++) {

            while (pos < n) {

                // Exact match
                if (word1[pos] == word2[i]) {
                    ans.push_back(pos);
                    pos++;
                    break;
                }

                // Use the one allowed mismatch
                if (!usedMismatch) {

                    // If this is the last character,
                    // we can always use the mismatch.
                    if (i == m - 1) {
                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        break;
                    }

                    // Remaining word2[i+1...] must be
                    // possible after pos.
                    if (suf[i + 1] < n && suf[i + 1] > pos) {
                        ans.push_back(pos);
                        pos++;
                        usedMismatch = true;
                        break;
                    }
                }

                pos++;
            }

            if ((int)ans.size() != i + 1)
                return {};
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna