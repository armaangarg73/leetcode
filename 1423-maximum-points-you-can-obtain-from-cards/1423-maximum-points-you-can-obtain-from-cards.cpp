class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        int res = 0;
        int low = 0;
        int w = n - k;
        int high = w - 1;

        int sum = 0;

        for (int i = low; i <= high; i++) {
            sum += cardPoints[i];
        }

        res = sum;
        while (high < n) {
            low++;
            high++;

            if (high == n) {
                break;
            }
            sum -= cardPoints[low - 1];
            sum += cardPoints[high];

            res = min(res , sum);
        }
        return total - res ;
    }
};