class Solution {
public:

    bool valid(int i , int j , int n , int m) {
        if(i<0 || i>=n || j<0 || j>=m) {
            return false ;
        }
        return true ;
    }

    void dfs(vector<vector<char>>& grid , vector<vector<bool>>& visited , int n , int m , int i , int j) {
        visited[i][j] = 1 ;
        int x[4] = {-1 , 1 , 0 , 0};
        int y[4] = {0 , 0 , -1 , 1} ;

        for(int k = 0 ; k<4 ; k++) {
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row , col , n , m) && visited[row][col] == 0 && grid[row][col] == '1') {
                dfs(grid , visited , n , m , row , col);
            }
        }
        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size() ;
        int res = 0 ;

        vector<vector<bool>>visited(n);
        for(int i = 0 ; i<n ; i++) {
            vector<bool>t(m,0);
            visited[i] = t ;
        }

        for(int i = 0 ;i<n ; i++) {
            for(int j = 0 ;j<m ; j++) {
                if(visited[i][j] == 0 && grid[i][j]=='1'){
                    dfs(grid , visited ,  n , m , i , j) ;
                    res++;
                }               
            }
        }
        return res ;
    }
};