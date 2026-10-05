class Solution {
public:

    struct cmp {
        bool operator() (pair<int,int>& a , pair<int,int>& b) {
            if(a.first!=b.first) {
               return a.first<b.first;
            }

            return a.second<b.second ;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size() ;
        int m = mat[0].size() ;

        priority_queue<pair<int,int> , vector<pair<int,int>> , cmp> pq ;

        for(int i = 0 ;i<n ; i++) {
            int soldiers = 0 ;
            for(int j = 0 ; j<m ; j++) {
                if(mat[i][j]==1) {
                    soldiers++;
                }
            }

            pair<int , int> curr = {soldiers , i} ;

            if(pq.size()<k) {
                pq.push(curr);
            }

            else if(curr.first<pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int>res ;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin() , res.end());

        return res ;
    }
};