class Solution {
public:

    bool cycle = false ;

    void dfs(vector<vector<int>>& prerequisites , vector<bool>& visited , vector<bool>& path , int node) {
        visited[node] = 1 ;
        path[node] = 1 ;

        for(int j = 0 ; j <prerequisites[node].size() ; j++) {
            int neigh = prerequisites[node][j] ;
            if(visited[neigh] == 1 && path[neigh] == 1) {
                cycle = true ;
            }

            if(visited[neigh]==0) {
                dfs(prerequisites , visited , path , neigh);
            }
        }
        path[node] = 0 ;
        return ;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>a(numCourses) ;

        for(int i = 0 ; i<prerequisites.size() ; i++) {
            int dest = prerequisites[i][0] ;
            int src = prerequisites[i][1] ;

            a[src].push_back(dest);
        }

        vector<bool>visited(numCourses , 0) ;
        vector<bool>path(numCourses , 0) ;

        for(int i = 0 ; i<numCourses ; i++) {
            if(visited[i] == 0) {
                dfs(a , visited , path , i);
            }
        }
        return !cycle ;
    }
};