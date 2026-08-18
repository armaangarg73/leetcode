class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq ;

        long long sum = 0 ;
        long long best = 0 ;

        int low = 0 ;
        for(int high = 0 ; high<nums.size() ; high++) {
            sum+=nums[high] ;
            freq[nums[high]]++;

            if(high>=k) {
                sum = sum - nums[low];
                freq[nums[low]]--;

                if(freq[nums[low]]==0) {
                    freq.erase(nums[low]);
                }
                low++;
            }

            if(high-low+1 == k) {
                if(freq.size() < k) {
                    continue ;
                }

                best = max(best , sum);
            }
        }
        return best ;
    }
};