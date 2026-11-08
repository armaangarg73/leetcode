class Solution {
public:

    void  printPermutaions(vector<int>& nums , int index , vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back({nums});
            return ;
        }
        for(int j = index ; j<nums.size() ; j++){
            swap(nums[index] , nums[j]);
             printPermutaions(nums , index+1 , ans);
             swap(nums[index] , nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0 ;
        vector<vector<int>>ans ;
        printPermutaions(nums , index , ans);
        return ans ;
    }
};