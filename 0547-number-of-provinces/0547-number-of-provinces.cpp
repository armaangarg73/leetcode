class Solution {
public:

    void dfs(vector<vector<int>>& isConnected,
             vector<bool>& visited, int i, int n) {

        visited[i] = 1;

        for(int j = 0; j < n; j++) {

            if(isConnected[i][j] == 1 &&
               visited[j] == 0) {

                dfs(isConnected, visited, j, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        vector<bool> visited(n, 0);

        int res = 0;

        for(int i = 0; i < n; i++) {

            if(visited[i] == 0) {

                dfs(isConnected, visited, i, n);

                res++;
            }
        }

        return res;
    }
};