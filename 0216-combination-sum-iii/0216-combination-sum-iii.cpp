class Solution {
public:

    void solve(int n , int idx , vector<int>& diary , int k , int sum , vector<vector<int>>& res) {
        if(idx==10) {
            if(sum==n && diary.size()==k) {
                res.push_back(diary);
            }
            return ;
        }

        // nhi leni hai

        solve(n , idx+1 , diary , k , sum , res);

        // leni hai

        if(sum + idx <=n && diary.size()<k) {
            diary.push_back(idx);
            sum += idx ;

            solve(n , idx+1 , diary , k , sum , res);
            diary.pop_back();
            sum -=idx ;
        }
        return ;
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res ;
        vector<int>diary ;
        int sum = 0 ;
        solve(n , 1 , diary , k , sum , res);
        return res ;
    }
};