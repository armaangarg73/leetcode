class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1 ;
        int count = 0 ;

        for(int i = 0 ; i<nums.size() ; i++) {
            if(count == 0) {
                candidate = nums[i] ;
                count = 1 ;
            }

            else if(nums[i] == candidate) {
                count = count+1 ;
            }
            else {
                count = count-1 ;
            }
        }
        return candidate ;
    }
};