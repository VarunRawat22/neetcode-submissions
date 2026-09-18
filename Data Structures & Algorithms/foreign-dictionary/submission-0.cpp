class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        // Mark all characters which are present
        for(auto &word : words) {
            for(char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        int n = words.size();

        // Compare adjacent words
        for(int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            int j = 0;

            // Skip same prefix
            while(j < len && s1[j] == s2[j]) {
                j++;
            }

            // Invalid case: ["abc", "ab"]
            if(j == len) {
                if(s1.size() > s2.size()) {
                    return "";
                }

                continue;
            }

            // First different character gives ordering
            int u = s1[j] - 'a';
            int v = s2[j] - 'a';

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push all characters having indegree 0
        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";

        // Kahn's Algorithm
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for(int nei : adj[node]) {

                indegree[nei]--;

                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Count unique characters
        int total = 0;

        for(int i = 0; i < 26; i++) {
            if(present[i]) {
                total++;
            }
        }

        // Cycle present
        if(ans.size() != total) {
            return "";
        }

        return ans;
    }
};