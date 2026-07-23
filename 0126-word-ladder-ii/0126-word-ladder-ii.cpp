class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_set<string> curr{beginWord}, visited;
        bool found = false;

        while (!curr.empty() && !found) {
            for (auto &w : curr) visited.insert(w);

            unordered_set<string> next;

            for (string word : curr) {
                string temp = word;

                for (int i = 0; i < temp.size(); i++) {
                    char old = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;

                        if (!dict.count(temp) || visited.count(temp))
                            continue;

                        if (temp == endWord)
                            found = true;

                        next.insert(temp);
                        parent[temp].push_back(word);
                    }

                    temp[i] = old;
                }
            }

            curr = next;
        }

        if (!found) return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna