class Solution {
public:

    bool dfs(vector<vector<char>>& grid,
             vector<vector<bool>>& visited,
             int row, int col,
             int prow, int pcol) {

        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = true;

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nrow = row + x[k];
            int ncol = col + y[k];

            // Out of bounds
            if(nrow < 0 || nrow >= n ||
               ncol < 0 || ncol >= m) {
                continue;
            }

            // Different character
            if(grid[nrow][ncol] != grid[row][col]) {
                continue;
            }

            // Already visited
            if(visited[nrow][ncol]) {

                // If it is NOT the parent → cycle
                if(nrow != prow || ncol != pcol) {
                    return true;
                }
            }

            // Not visited
            else {

                if(dfs(grid, visited,
                       nrow, ncol,
                       row, col)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)
        );

        for(int row = 0; row < n; row++) {

            for(int col = 0; col < m; col++) {

                if(visited[row][col] == false) {

                    if(dfs(grid, visited,
                           row, col, -1, -1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};