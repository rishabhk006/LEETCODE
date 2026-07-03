class Solution {
public:
    bool check(int val, vector<vector<pair<int,int>>> &adj,
               vector<bool>& online, long long k) {

        int n = online.size();
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (w < val) continue;
                if (v != n - 1 && !online[v]) continue;

                if (cost + w < dist[v] && cost + w <= k) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);

        int high = 0;
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            high = max(high, e[2]);
        }

        int low = 0, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, adj, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna