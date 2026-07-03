class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna