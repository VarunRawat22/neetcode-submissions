class Solution {

    void dfs(int row, int col,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        int n = heights.size();
        int m = heights[0].size();

        vis[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               heights[nrow][ncol] >= heights[row][col]) {

                dfs(nrow, ncol, heights, vis);
            }
        }
    }

public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        // Pacific: top and left
        for(int col = 0; col < m; col++) {
            dfs(0, col, heights, pacific);
        }

        for(int row = 0; row < n; row++) {
            dfs(row, 0, heights, pacific);
        }

        // Atlantic: bottom and right
        for(int col = 0; col < m; col++) {
            dfs(n - 1, col, heights, atlantic);
        }

        for(int row = 0; row < n; row++) {
            dfs(row, m - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(pacific[row][col] && atlantic[row][col]) {
                    ans.push_back({row, col});
                }
            }
        }

        return ans;
    }
};