class Solution {
public:

    void subsequence(vector<int>& nums , vector<int>& output , vector<vector<int>>& ans , int idx) {
        if(idx>=nums.size()) {
            ans.push_back({output});
            return ;
        }
        // nhi lenge
        subsequence(nums , output , ans , idx+1);
        // lenge
        output.push_back({nums[idx]});
        subsequence(nums , output , ans , idx+1);
        output.pop_back();
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output ;
        vector<vector<int>>ans ;
        subsequence(nums , output , ans , 0);
        return ans ;
    }
};