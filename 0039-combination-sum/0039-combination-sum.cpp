class Solution {
public:
    void fun(vector<int>& a, int n, int idx, vector<int>& diary,
             vector<vector<int>>& res, int sum, int target) {
        if (idx == n) {
            if (sum == target) {
                res.push_back(diary);
            }
             return;
        }
            // nhi lena hai

            fun(a, n, idx + 1, diary, res, sum, target);

            if (a[idx] + sum <= target) {
                diary.push_back(a[idx]);
                sum = sum + a[idx];
                fun(a, n, idx, diary, res, sum, target);
                diary.pop_back();
                sum = sum - a[idx];
        }
            return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>diary ;
        int sum = 0 ;
        int n = candidates.size() ;
        vector<vector<int>> res ;
        int idx = 0 ;
        fun(candidates , n , idx , diary , res , sum , target);
        return res ;
    }
};