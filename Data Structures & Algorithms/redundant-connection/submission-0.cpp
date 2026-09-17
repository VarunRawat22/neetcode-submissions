class Solution {
    
    // Finds the ultimate parent/root of a node
    int findParent(int node, vector<int>& parent) {

        // If node itself is parent, this is the root
        if(parent[node] == node)
            return node;

        // Path compression:
        // directly connect node with its ultimate parent
        return parent[node] = findParent(parent[node], parent);
    }


    // Connect two different components
    void unionBySize(int u, int v,
                     vector<int>& parent,
                     vector<int>& size) {

        // Find ultimate parents
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        // Already same component
        if(pu == pv)
            return;

        // Attach smaller component under larger component
        if(size[pu] < size[pv]) {

            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {

            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }


public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Number of nodes
        int n = edges.size();

        vector<int> parent(n + 1);
        vector<int> size(n + 1, 1);

        // Initially every node is its own parent
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }


        // Process every edge
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Find ultimate parents of both nodes
            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            // If same parent => already connected
            // Adding this edge will create a cycle
            if(pu == pv) {
                return {u, v};
            }

            // Otherwise safely connect them
            unionBySize(u, v, parent, size);
        }

        return {};
    }
};