class Solution {
public:

    struct cmp {
        bool operator() (pair<int , int>& a , pair<int , int>& b) {
            if(a.first!=b.first) {
                return a.first<b.first ;
            }

            return a.second<b.second ;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , cmp> pq ;

        for(int i = 0 ; i<matrix.size() ; i++) {
            for(int j = 0 ; j<matrix[0].size() ; j++) {
                
            int value = matrix[i][j];

                pair<int, int> curr = {value, j};

                if (pq.size() < k) {
                    pq.push(curr);
                }
                else if (curr.first < pq.top().first) {
                    pq.pop();
                    pq.push(curr);
                }
            }
        }

        vector<int>res ;

        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res[k-1];
    }
};