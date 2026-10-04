class Solution {
public:
    struct cmp {
        bool operator()(pair<double, int>& a,
                        pair<double, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<double, int>, vector<pair<double, int>>, cmp> pq;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            double dist = sqrt(x * x + y * y);

            pair<double, int> curr = {dist, i};

            if (pq.size() < k) {
                pq.push(curr);
            } else if (curr.first < pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};