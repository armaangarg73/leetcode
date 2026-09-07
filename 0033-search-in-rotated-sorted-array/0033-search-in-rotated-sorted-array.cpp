class Solution {
public:

     int binarySearch(vector<int>& arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;

            else if (arr[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1 ;

         while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        int minIndex = low ;

        if (target >= nums[minIndex] && target <= nums[nums.size() - 1]) {
            return binarySearch(nums, minIndex, nums.size() - 1, target);
        }
        else {
            return binarySearch(nums, 0, minIndex - 1, target);
        }
    }
};