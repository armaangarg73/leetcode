class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0 ;
        int high = nums.size()-1 ;
        int ans = -1 ;

        while(low<=high) {
            int mid = (low+high)/2 ;
            if(mid+1 < nums.size() && nums[mid]<nums[mid+1]) {
                low = mid+1 ;
            }
            else {
                ans = mid ;
                high = mid-1 ;
            }
        }
        return ans ;
    }
};