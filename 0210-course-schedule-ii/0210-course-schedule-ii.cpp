class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> a(numCourses) ;
        vector<int>indeg(numCourses , 0);
        for(int i = 0 ; i<prerequisites.size() ; i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1] ;

            a[src].push_back(dest);
            indeg[dest]++;
        }

        queue<int>q ;

        for(int i = 0 ; i<numCourses ; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int>res ;

        while(!q.empty()) {
            int node = q.front() ; 
            q.pop() ;

            res.push_back(node) ;
            for(int j = 0 ; j<a[node].size() ; j++) {
                int neigh = a[node][j] ;
                indeg[neigh]-- ;

                if(indeg[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
         if(res.size() != numCourses) {
            return {};
        }
        return res ;
    }
};