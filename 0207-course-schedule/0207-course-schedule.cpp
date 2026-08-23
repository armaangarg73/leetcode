class Solution {
public:

    bool cycle = false ;

    void dfs(vector<vector<int>>& prerequisites , int node , vector<bool>& visited , vector<bool>& path) {
        visited[node] = 1 ;
        path[node] = 1 ;

        for(int j = 0 ; j<prerequisites[node].size() ; j++) {
            int neigh = prerequisites[node][j];

            if(visited[neigh] == 1 && path[neigh] == 1) {
                cycle = true ;
            }

            if(visited[neigh] == 0) {
                dfs(prerequisites , neigh , visited , path);
            }
        }
        path[node] = 0 ;
        return ;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>a(numCourses);
        int n = prerequisites.size() ;
        for(int i = 0 ; i<n ; i++) {
            int dest = prerequisites[i][0] ;
            int src = prerequisites[i][1] ;

            a[dest].push_back(src);
        }

        vector<bool>visited(numCourses , 0);
        vector<bool>path(numCourses , 0);

        for(int i = 0 ; i<numCourses ; i++) {
            if(visited[i] == 0) {
                dfs(a , i , visited , path);
            }
        }
        return !cycle ;
    }
};