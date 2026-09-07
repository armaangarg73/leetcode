class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(nums[mid] == target) {
                return true;
            }

            // duplicate case
            if(nums[low] == nums[mid] && nums[high] == nums[mid]) {
                low++;
                high--;
                continue;
            }

            // part1
            if(nums[mid] > nums[high]) {

                if(nums[mid] < target) {
                    low = mid + 1;
                }
                else {
                    if(nums[low] > target) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
            }

            // part2
            else {

                if(nums[mid] > target) {
                    high = mid - 1;
                }
                else {
                    if(nums[high] < target) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
            }
        }

        return false;
    }
};