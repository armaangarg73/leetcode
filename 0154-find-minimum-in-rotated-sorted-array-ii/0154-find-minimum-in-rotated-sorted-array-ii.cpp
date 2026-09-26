class Solution {
public:
    int findMin(vector<int>& nums) {
     int low = 0;
        int high = nums.size() - 1;
       

        while (low < high) {
            int mid = low + (high - low) / 2;

            // minimum lies in right part
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // minimum lies in left part including mid
            else if (nums[mid] < nums[high]) {
                high = mid ;
            }
            // duplicates case
            else {
                high--;
            }
        }
        return nums[low];
    }
};