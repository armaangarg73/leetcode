class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size() ;

        priority_queue<int>pq ;

        int start = startFuel ;
        int result = 0 ;
        int i = 0 ;

        while(start<target){
        while(i<n && start>=stations[i][0]) { // first station
            pq.push(stations[i][1]);
            i++;
        }

        if(pq.empty()) return -1 ;

        int dist = pq.top();
        pq.pop();

        start = start + dist ;
        result++;
        }
        return result ;
    }
};