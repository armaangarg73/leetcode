class Solution {
public:

    bool valid(int i , int j , int n , int m) {
        if(i<0 || i>=n || j<0 || j>=m){
            return false ;
        }
        return true ;
    }

    void dfs(vector<vector<char>>& board , vector<vector<bool>>& visited , int n , int m , int i , int j) {
        visited[i][j] = 1 ;
        int x[4] = {-1 , 1 , 0 , 0};
        int y[4] = {0 , 0 , -1 , 1};

        for(int k = 0 ; k<4 ; k++) {
            int row = i + x[k] ;
            int col = j + y[k] ;

            if(valid(row , col , n , m) && visited[row][col] == 0 && board[row][col] == 'O') {
                dfs(board , visited , n , m , row , col);
            }
        }
        return ;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size() ; 
        int m = board[0].size() ;

        vector<vector<bool>> visited(n);
        for(int i = 0 ; i<n ; i++) {
            vector<bool>t(m,0);
            visited[i] = t ;
        }

        for(int i = 0 ; i<n ; i++) {
            if(board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(board , visited , n , m , i , 0);
            }
            if(board[i][m-1] == 'O' && visited[i][m-1] == 0) {
                dfs(board , visited , n , m , i , m-1);
            }
        }
        for(int j = 0 ; j<m ; j++) {
            if(board[0][j] == 'O' && visited[0][j] == 0) {
                dfs(board , visited , n , m , 0 , j);
            }
            if(board[n-1][j] == 'O' && visited[n-1][j] == 0) {
                dfs(board , visited , n , m , n-1 , j);
            }
        }

        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if(board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};