
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Step 1: Create adjacency list
        vector<pair<int,int>> adj[n + 1];

        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        // Step 2: Distance array
        vector<int> dist(n + 1, INT_MAX);

        // Step 3: Min heap {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        // Step 4: Dijkstra
        while(!pq.empty()) {

            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if(dis > dist[node]) continue;

            for(auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]) {

                    dist[adjNode] = dis + wt;

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Step 5: Find maximum distance
        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
