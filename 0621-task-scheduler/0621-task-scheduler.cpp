class Solution {
public:
    struct cmp {
        bool operator() (pair<int, char>& a, pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }

            return a.second < b.second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        for (auto i : tasks) {
            freq[i]++;
            free[i] = 1;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;

        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        int seat = 1;

        while (!pq.empty()) {
            vector<pair<int, char>> pulled; // kona hai yeh
            while (!pq.empty()) {
                pair<int, char> p = pq.top();
                pq.pop();

                int freq = p.first;
                char child = p.second;

                if (free[child] <= seat) {
                    if (freq > 1) {
                        pq.push({freq - 1, child});
                    }

                    free[child] = seat + n + 1;
                    break;
                }

                else {
                    pulled.push_back(p); // kone me bhejdo ek baar
                }
            } // checking vala loop hai -> heap empty hogya hai to isko exit krjao

            for (int i = 0; i < pulled.size(); i++) {
                pq.push(pulled[i]);
            }

            seat++;
        }

        return seat-1;
    }
};