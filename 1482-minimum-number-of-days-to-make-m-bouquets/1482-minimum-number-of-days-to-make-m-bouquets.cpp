class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int mid, int m, int k) {
        int cnt = 0;
        int bouquets = 0;

        for (int day : bloomDay) {
            if (day <= mid) {
                cnt++;
            } else {
                bouquets += (cnt / k);
               cnt = 0;
            }
        }
         bouquets += (cnt / k);
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size())
            return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};