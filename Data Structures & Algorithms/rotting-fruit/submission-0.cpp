class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // {{row, col}, time}
        queue<pair<pair<int,int>,int>> q;

        // Initially rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int t = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();

            t = max(t, time);

            // Check 4 neighbours
            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 2 &&
                   grid[nrow][ncol] == 1) {

                    // Orange becomes rotten
                    vis[nrow][ncol] = 2;

                    q.push({{nrow, ncol}, time + 1});
                }
            }
        }

        // After complete BFS check if any fresh orange remains
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        return t;
    }
};