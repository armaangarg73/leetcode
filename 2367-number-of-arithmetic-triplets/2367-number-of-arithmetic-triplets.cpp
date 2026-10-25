class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size() ;

        int ans = 0 ;

        for(int i = 0 ; i<n ;i++) {
            int j = i+1 ;
            int k = n-1 ;

            while(j<k) {
                if(nums[j]-nums[i]==diff && nums[k]-nums[j]==diff) {
                    ans++;
                    break ;
                }

                else if(nums[j]-nums[i]<diff){
                    j++;
                }

                else {
                    k--;
                }
            }
        }
        return ans ;
    }
};