class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        path += '/';

        for (char c : path) {
            if (c == '/') {
                if (cur == "..") {
                    if (!st.empty())
                        st.pop_back();
                }
                else if (!cur.empty() && cur != ".") {
                    st.push_back(cur);
                }
                cur.clear();
            } else {
                cur += c;
            }
        }

        if (st.empty())
            return "/";

        string ans;

        for (string &dir : st)
            ans += "/" + dir;

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna