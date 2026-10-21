class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int pivot = -1 ;

        // checking from back kyuki piche vale saare descennding order me honge , jonsa pehla  element nhi hoga descending me voh pivot hoyga

        for(int i = n-2 ; i>=0 ; i--) {
            if(nums[i]<nums[i+1]) {
                pivot = i ;
                break ;
            }
        }

        // if no pivot is found

        if(pivot == -1) {
            reverse(nums.begin() , nums.end());
            return ;
        }

        // next larger element

        for(int i = n-1 ; i>pivot ; i--) {
            if(nums[i]>nums[pivot]) {
                swap(nums[i] , nums[pivot]) ;
                break ;
            }
        }

        // reverse rest of the numbers -> piv+1 , end tk

        int i = pivot+1 ;
        int j = n-1 ;

        while(i<=j) {
            swap(nums[i] , nums[j]) ;
            i++;
            j--;
        }
    }
};