class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1 ;

        while(low<=high) {
            int mid = (low+high)/2 ;
            if(nums[mid]==target) {
                return mid ;
            }
    // part1
            if(nums[mid]>nums[nums.size()-1]) {
                if(nums[mid]<target) {
                    low = mid+1 ;
                }
                else {
                    if(nums[0]>target) {
                        low = mid+1 ;
                    }
                    else {
                        high = mid-1 ;
                    }
                }
            }
// part2

            else {
                if(nums[mid]>target) {
                    high = mid-1 ;
                }
                else {
                    if(nums[nums.size()-1]<target) {
                        high = mid-1 ;
                    }

                    else {
                        low = mid+1;
                    }
                }
            }
        }
        return -1 ;
    }
};