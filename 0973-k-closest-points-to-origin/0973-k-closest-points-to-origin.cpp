class Solution {
public:
    struct cmp {
        bool operator()(pair<double, vector<int>>& a,
                        pair<double, vector<int>>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double, vector<int>>,
                       vector<pair<double, vector<int>>>, cmp>
            pq;

        for (auto point : points) {

            int x = point[0];
            int y = point[1];

            double dist = sqrt((x - 0) * (x - 0) + (y - 0) * (y - 0));

            pair<double, vector<int>> curr = {dist, point};

            if (pq.size() < k) {
                pq.push(curr);
            } else if (curr.first < pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};