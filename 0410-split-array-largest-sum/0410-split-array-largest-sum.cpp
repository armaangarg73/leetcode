class Solution {
public:

    bool isPossible(vector<int>& nums , int n , long long limit , int sub) {
        int k = 1 ;
        long long splitSum = 0 ;

        for(int i = 0 ; i<n ; i++) {
            if(splitSum + nums[i] <= limit) {
                splitSum+=nums[i];
            }
            else {
                k++ ;
                splitSum = nums[i];
            }
            if(k>sub) {
                return false ;
            }
        }
        return true ;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        if(n<k){
            return -1 ;
        }
        long long low = 0 ;
        long long high ;

        for(int i = 0 ; i<n ; i++) {
            low = max(low , (long long)nums[i]);
            high+=nums[i];
        }
        long long res = -1 ;

        while(low<=high) {
            long long mid = (low+high)/2 ;
            if(isPossible(nums , n , mid , k)) {
                res = mid ;
                high = mid-1 ;
            }

            else {
                low = mid+1 ;
            }
        }
        return (int)res ;
    }
};