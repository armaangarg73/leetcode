class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        long long sum = 0;
        long long best = 0;

        int low = 0;

        for (int high = 0; high < nums.size(); high++) {

            // absorb arr[high]
            sum += nums[high];
            freq[nums[high]]++;

            // if high >= K, drop arr[low]
            if (high >= k) {
                sum -= nums[low];
                freq[nums[low]]--;

                if (freq[nums[low]] == 0) {
                    freq.erase(nums[low]);
                }

                low++;
            }

            // window is full
            if (high - low + 1 == k) {

                // duplicate exists
                if (freq.size() < k) {
                    continue;
                }

                best = max(best, sum);
            }
        }

        return best;
    }
};