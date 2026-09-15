class Solution {

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        // Mark current node as visited
        vis[node] = 1;

        // Visit all connected neighbours
        for(int nei : adj[node]) {

            // Explore only unvisited neighbours
            if(!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

public:

    int countComponents(int n, vector<vector<int>>& edges) {

        // Create adjacency list
        vector<vector<int>> adj(n);

        // Build undirected graph
        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Undirected edge goes both ways
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Track visited nodes
        vector<int> vis(n, 0);

        int cnt = 0;

        // Check every node because graph may be disconnected
        for(int i = 0; i < n; i++) {

            // Unvisited node means a new component is found
            if(!vis[i]) {

                cnt++;

                // Mark the entire component as visited
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};