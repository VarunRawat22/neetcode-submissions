class Solution {

    void dfs(int row, int col,
             vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, board, vis);
            }
        }
    }

public:

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Check top and bottom boundary
        for(int col = 0; col < m; col++) {

            if(board[0][col] == 'O' && !vis[0][col])
                dfs(0, col, board, vis);

            if(board[n - 1][col] == 'O' && !vis[n - 1][col])
                dfs(n - 1, col, board, vis);
        }

        // Check left and right boundary
        for(int row = 0; row < n; row++) {

            if(board[row][0] == 'O' && !vis[row][0])
                dfs(row, 0, board, vis);

            if(board[row][m - 1] == 'O' && !vis[row][m - 1])
                dfs(row, m - 1, board, vis);
        }

        // Convert only O's not connected to boundary
        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(board[row][col] == 'O' &&
                   !vis[row][col]) {

                    board[row][col] = 'X';
                }
            }
        }
    }
};