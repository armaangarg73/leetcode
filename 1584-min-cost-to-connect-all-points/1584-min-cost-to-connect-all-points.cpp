class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        vector<vector<pair<int,int>>> a(V);

        for(int i = 0; i < V; i++) {

            for(int j = i + 1; j < V; j++) {

                int src = i;
                int dest = j;

                int wt = abs(points[src][0] - points[dest][0])
                       + abs(points[src][1] - points[dest][1]);

                a[src].push_back({dest, wt});
                a[dest].push_back({src, wt});
            }
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        int sum = 0;

        vector<int> visited(V, 0);

        pq.push({0, 0});

        while(!pq.empty()) {

            pair<int,int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if(visited[node] == 1) {
                continue;
            }

            visited[node] = 1;
            sum = sum + d;

            for(int j = 0; j < a[node].size(); j++) {

                int neigh = a[node][j].first;
                int wt = a[node][j].second;

                if(visited[neigh] == 0) {
                    pq.push({wt, neigh});
                }
            }
        }

        return sum;
    }
};