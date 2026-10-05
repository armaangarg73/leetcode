class Solution {
public:

    bool isPossible(vector<int>& nums, int p, int n, int mid) {
        int pairs = 0;

        for(int i = 0; i < n - 1; i++) {

            int diff = nums[i + 1] - nums[i];

            if(diff > mid) {
                continue;
            }

            pairs++;
            i++;

            if(pairs >= p) {
                return true;
            }
        }

        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {

        int n = nums.size();

        if(p == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n - 1] - nums[0];

        int res = -1;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(isPossible(nums, p, n, mid)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return res;
    }
};