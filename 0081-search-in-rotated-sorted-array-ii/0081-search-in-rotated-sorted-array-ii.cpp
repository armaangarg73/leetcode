class Solution {
public:

    bool bs(vector<int>& nums, int target , int high , int low) {

        while(low<=high) {
            int mid = (low+high)/2 ;
            if(nums[mid]==target){
                return true ;
            }
            else if(nums[mid]<target) {
                low = mid+1 ;
            }
            else {
                high = mid-1 ;
            }
        }
        return false ;
    }

    bool search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1 ;

        while(low<high) {
            int mid = (low+high)/2 ;
            if(nums[mid]>nums[high]) {
                low = mid+1 ;
            }

            else if(nums[mid]<nums[high]){
                high = mid ;
            }

            else {
                high--;
            }
        }
         int minValue = nums[low];

        // Step 2: Find ACTUAL rotation point
        // i.e. position where previous element > current element
        int minIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                minIndex = i;
                break;
            }
        }

        // No rotation
        if (minIndex == 0 && nums[0] == minValue) {
            return bs(nums, target, nums.size() - 1, 0);
        }
        if (target >= nums[minIndex] && target <= nums[nums.size() - 1]) {
            return bs(nums, target , nums.size()-1 , minIndex);
        }
        else {
            return bs(nums, target, minIndex - 1, 0);
        }
    }
};