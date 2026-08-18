class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2 ;
        int ans = INT_MAX ;

        while(s<=e){
            if(nums[s]<=nums[mid]){
               ans = min(ans ,nums[s]);
                s = mid+1 ;
            }

            else{
               if(nums[mid]<ans){
                ans = nums[mid];
               }
               e= mid-1 ;
            }
            mid = s+(e-s)/2 ;
        }
        return ans;
    }
};