class Solution {
public:
     void flood(int r, int c, vector<vector<int>>& heights,
               vector<vector<bool>>& reach , int n , int m) {

        reach[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !reach[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                flood(nr, nc, heights, reach , n , m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row and left column
        for (int c = 0; c < n; c++) {
            flood(0, c, heights, pacific , n , m);
        }

        for (int r = 0; r < m; r++) {
            flood(r, 0, heights, pacific , n , m);
        }

        // Atlantic: bottom row and right column
        for (int c = 0; c < n; c++) {
            flood(m - 1, c, heights, atlantic , n , m);
        }

        for (int r = 0; r < m; r++) {
            flood(r, n - 1, heights, atlantic , n , m);
        }

        // Intersection
        vector<vector<int>> ans;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};