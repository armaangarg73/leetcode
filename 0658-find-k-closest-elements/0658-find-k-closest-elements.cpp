class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

            for (int i = 0; i < arr.size(); i++) {

               int diff = abs(arr[i]-x);

                pair<int, int> curr = {diff, arr[i]};

                if (pq.size() < k) {
                    pq.push(curr);
                } else if (curr.first < pq.top().first) {
                    pq.pop();
                    pq.push(curr);
                }
            }

            vector<int> res;

            while (!pq.empty()) {
                res.push_back(pq.top().second);
                pq.pop();
            }

            sort(res.begin(), res.end());

            return res;
        }
    };