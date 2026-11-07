class Solution {
public:

     void solve(vector<int>& nums, vector<int>& path,
               vector<bool>& used, vector<vector<int>>& ans) {

        // Base case: complete permutation
        if(path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        // Try every unused number
        for(int i = 0; i < nums.size(); i++) {

            if(!used[i]) {

                // Choose
                used[i] = true;
                path.push_back(nums[i]);

                // Explore
                solve(nums, path, used, ans);

                // Backtrack (un-choose)
                used[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        solve(nums, path, used, ans);

        return ans;
    }
};