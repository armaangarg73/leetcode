class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        int sum = 0;

        vector<int> visited(n, 0);

        pq.push({0, 0});

        while(!pq.empty()) {

            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if(visited[node] == 1) {
                continue;
            }

            visited[node] = 1;
            sum = sum + d;

            // Check all possible neighbouring points
            for(int j = 0; j < n; j++) {

                if(visited[j] == 0) {

                    int wt = abs(points[node][0] - points[j][0])
                           + abs(points[node][1] - points[j][1]);

                    pq.push({wt, j});
                }
            }
        }

        return sum;
    }
};