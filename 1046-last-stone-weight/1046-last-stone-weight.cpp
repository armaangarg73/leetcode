class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size() ;
        priority_queue<int>pq ;

        for(int i : stones) {
            pq.push(i);
        }

        while(pq.size()>1) {
            int x = pq.top() ;
            pq.pop() ;

            int y = pq.top() ;
            pq.pop();

            if(x!=y) {
            int diff = abs(y-x) ;
            pq.push(diff) ;
            }

            if(pq.empty()) return 0 ;
        }
        return pq.top() ;
    }
};