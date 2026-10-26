class Solution {
public:

    void subsequence(vector<int>& nums , int index , vector<int>& output , vector<vector<int>>& ans) {
        if(index>=nums.size()){
            ans.push_back({output});
            return ;
        }
        output.push_back(nums[index]);
        subsequence(nums , index+1 , output , ans);
        output.pop_back();

        int idx = index+1 ;
        while(idx<nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        subsequence(nums , idx , output , ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int index = 0 ;
        vector<int>output ;
        vector<vector<int>>ans ;
        subsequence(nums , index , output , ans);
        return ans ;
    }
};