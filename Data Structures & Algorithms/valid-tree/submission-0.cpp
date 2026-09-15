class Solution {

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        // Mark current node as visited
        vis[node] = 1;

        // Visit every unvisited neighbour
        for(int nei : adj[node]) {

            if(!vis[nei])
                dfs(nei, adj, vis);
        }
    }

public:

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have exactly n-1 edges
        if(edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        // Build undirected adjacency list
        for(auto &edge : edges) {

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);

        // Check connectivity from node 0
        dfs(0, adj, vis);

        // Any unvisited node means graph is disconnected
        for(int i = 0; i < n; i++) {

            if(!vis[i])
                return false;
        }

        // n-1 edges + connected graph = tree
        return true;
    }
};